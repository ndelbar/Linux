#include "Grid.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

CGrid::CGrid(const int nRowCount, const int nColCount)
{
	m_pnGridStart = new int[nRowCount * nColCount];

	m_nRowCount = nRowCount;
	m_nColCount = nColCount;

	m_pNodeList = new node*[nRowCount * nColCount];

	for (int i = 0; i < nRowCount * nColCount; ++i)
	{
		m_pNodeList[i] = NULL;
	}

}

CGrid::~CGrid()
{
		delete[] m_pnGridStart;

		for (int iNode = 0; iNode < m_nRowCount * m_nColCount; iNode++)
		{
			node* pNode = m_pNodeList[iNode];

			if (pNode)
				delete pNode;
		}
}

void CGrid::AddNode(const int& nRow, const int& nCol, const int& nVal, int nInitialVal, Direction eDirection, int nIteration)
{
	const int iPos = nRow * m_nColCount + nCol;

	if (!m_pNodeList[iPos])
	{
		node* pNode = new node;

		m_pNodeList[iPos] = pNode;
		m_pNodeList[iPos]->nVal = nVal;
		m_pNodeList[iPos]->nRow = nRow;
		m_pNodeList[iPos]->nCol = nCol;
		m_pNodeList[iPos]->eDirection = eDirection;

		if (nIteration < 0)
			nIteration = m_nCurrentIteration;

		m_pNodeList[iPos]->nIteration = nIteration;

		if (nInitialVal == -1)
			nInitialVal = nVal;

		m_pNodeList[iPos]->nInitialVal = nInitialVal;
	}
	else if (m_pNodeList[iPos]->nIteration == nIteration)
	{
		m_pNodeList[iPos]->eDirection = Direction::Initial;
		m_pNodeList[iPos]->nVal = max(m_pNodeList[iPos]->nInitialVal, nInitialVal);
	}
	else if (m_pNodeList[iPos]->nIteration < nIteration)
	{
		m_pNodeList[iPos]->nVal = nVal;
		m_pNodeList[iPos]->nRow = nRow;
		m_pNodeList[iPos]->nCol = nCol;
		m_pNodeList[iPos]->eDirection = eDirection;
		m_pNodeList[iPos]->nIteration = nIteration;
		m_pNodeList[iPos]->nInitialVal = nInitialVal;
	}

}

void CGrid::RemoveNode(int iCell, node* pNode)
{
	if (!pNode)
		return;

	m_pNodeList[iCell] = NULL;
	m_pnGridStart[iCell] = 0;
	delete pNode;
}

void CGrid::CalculateNextPhase()
{
	for (int iCell = 0; iCell < m_nRowCount * m_nColCount; ++iCell)
	{
		node* pNode = m_pNodeList[iCell];

		if (!pNode)
			continue;

		//cout << "Address: " << pNode << " Val: " << pNode->nVal << " Iteration: " << pNode->nIteration << endl;

		if (pNode->nIteration != m_nCurrentIteration)
			continue;

		if (pNode->nVal == 0)
		{
			RemoveNode(iCell, pNode);
			continue;
		}

		if (pNode->eDirection == Direction::Initial)
		{
			if (pNode->nRow + 1 < m_nRowCount)
				AddNode(pNode->nRow + 1, pNode->nCol, pNode->nVal - 1, pNode->nInitialVal, Direction::Down	, pNode->nIteration + 1);

			if (pNode->nRow - 1 >= 0)
				AddNode(pNode->nRow - 1, pNode->nCol, pNode->nVal - 1, pNode->nInitialVal, Direction::Up		, pNode->nIteration + 1);

			if (pNode->nCol + 1 < m_nColCount)
				AddNode(pNode->nRow, pNode->nCol + 1, pNode->nVal - 1, pNode->nInitialVal, Direction::Right	, pNode->nIteration + 1);

			if (pNode->nCol - 1 >= 0)
				AddNode(pNode->nRow, pNode->nCol - 1, pNode->nVal - 1, pNode->nInitialVal, Direction::Left	, pNode->nIteration + 1);

			RemoveNode(iCell, pNode);
		}
		else if (pNode->eDirection == Direction::Right)
		{
			if (pNode->nCol + 1 < m_nColCount)
				AddNode(pNode->nRow, pNode->nCol + 1, pNode->nVal - 1, pNode->nInitialVal, Direction::Right	, pNode->nIteration + 1);

			RemoveNode(iCell, pNode);
		}
		else if (pNode->eDirection == Direction::Left)
		{
			if (pNode->nCol - 1 >= 0)
				AddNode(pNode->nRow, pNode->nCol - 1, pNode->nVal - 1, pNode->nInitialVal, Direction::Left	, pNode->nIteration + 1);

			RemoveNode(iCell, pNode);
		}
		else if (pNode->eDirection == Direction::Up)
		{
			if (pNode->nRow - 1 >= 0)
				AddNode(pNode->nRow - 1, pNode->nCol, pNode->nVal - 1, pNode->nInitialVal, Direction::Up	, pNode->nIteration + 1);

			RemoveNode(iCell, pNode);
		}
		else if (pNode->eDirection == Direction::Down)
		{
			if (pNode->nRow + 1 < m_nRowCount)
				AddNode(pNode->nRow + 1, pNode->nCol, pNode->nVal - 1, pNode->nInitialVal, Direction::Down	, pNode->nIteration + 1);

			RemoveNode(iCell, pNode);
		}
	}

	++m_nCurrentIteration;
}

bool CGrid::IsNodesExist()
{
	for (int iNode = 0; iNode < m_nRowCount * m_nColCount; iNode++)
	{
		node* pNode = m_pNodeList[iNode];

		if (pNode)
			return true;
	}
	return false;
}

void CGrid::PopulateGrid()
{
	for (int iNode = 0; iNode < m_nRowCount * m_nColCount; iNode++)
	{
		node* pNode = m_pNodeList[iNode];

		//cout << "pNode: " << pNode << endl;

		if (pNode != NULL)
			m_pnGridStart[iNode] = pNode->nVal;
		else
			m_pnGridStart[iNode] = 0;
	}
}

void CGrid::PrintGrid()
{
	for (int iRow = 0; iRow < m_nRowCount; ++iRow)
	{
		for (int iCol = 0; iCol < m_nColCount; ++iCol)
		{
			const int nValue = m_pnGridStart[iRow * m_nColCount + iCol];

			if (nValue)
				printf("%d", m_pnGridStart[iRow * m_nColCount + iCol]);
			else
				printf(".");
		}
		printf("\r\n");
	}
}
