#ifndef GRID_H
#define GRID_H

#include <stdlib.h>

class CGrid
{
public:
	CGrid(const int nRowCount, const int nColCount);
	~CGrid();

	enum class Direction
	{
		Initial = 0,
		Up,
		Down,
		Left,
		Right
	};

	struct node
	{
		int nVal = 0;
		int nInstance = 0;
		int nRow = 0;
		int nCol = 0;
		Direction eDirection = Direction::Initial;
		int nIteration = 0;
		int nInitialVal = 0;
	};

	int m_nCurrentIteration = -1;

	node** m_pNodeList;

	void AddNode(const int& nRow, const int& nCol, const int& nVal, int nInitialVal = -1, Direction eDirection = Direction::Initial, int nIteration = -1);

	void PopulateGrid();

	void CalculateNextPhase();

	void PrintGrid();

	bool IsNodesExist();

	void RemoveNode(int iCell, node* pNode = NULL);

private:
	int* m_pnGridStart;
	int m_nRowCount;
	int m_nColCount;

};

#endif
