#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Piece.h"
#include <string>

using namespace std;

const int CBoard::m_nColCount = 8;
const int CBoard::m_nRowCount = 8;

const char g_cInitialSetupArray[CBoard::m_nRowCount][CBoard::m_nColCount] =
{
{'R','N','B','Q','K','B','N','R'},
{'P','P','P','P','P','P','P','P'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.'},
{'p','p','p','p','p','p','p','p'},
{'r','n','b','q','k','b','n','r'}
};

const string g_strBlank[3] =
{"     ",
 "     ",
 ".___."};

CBoard::CBoard()
{
  m_pCells = new CCell[m_nRowCount * m_nColCount];
}

CBoard::~CBoard()
{
  delete[] m_pCells;
}

void CBoard::InitializeGrid()
{
  for (int iRow = 0; iRow < m_nRowCount; ++iRow)
  {
    for(int iCol = 0; iCol < m_nColCount; ++iCol)
    {
      const char& cVal = g_cInitialSetupArray[iRow][iCol];

      CCell* pCurrentCell = &m_pCells[iRow * m_nColCount + iCol];

      pCurrentCell->SetRow(iRow);
      pCurrentCell->SetColumn(iCol);

      if (cVal != '.');
      {
        pCurrentCell->AddPiece(cVal);
      }
    }
  }
}

void CBoard::DisplayColumnValues()
{
  cout << endl;

  cout << "  ";

  for(char iCol = 0; iCol < m_nColCount; ++iCol)
  {
    for (int iRepeat = 0; iRepeat < g_strBlank[0].length(); ++iRepeat)
    {
      cout << (char)('a' + iCol);
    }
  }

  cout << endl << endl;
}

void CBoard::DisplayCurrentBoardState()
{
  DisplayColumnValues();

  for (int iRow = 0; iRow < m_nRowCount; ++iRow)
  {
    for (int iDisplayRow = 0; iDisplayRow < 3; iDisplayRow++)
    {
      cout << m_nRowCount - iRow << " ";

      for(int iCol = 0; iCol < m_nColCount; ++iCol)
      {
        CPiece* pPiece = m_pCells[iRow * m_nColCount + iCol].GetPiece();

        if (pPiece)
          pPiece->DisplayGraphic(iDisplayRow);
        else
          cout << g_strBlank[iDisplayRow];
      }

      cout << " " << m_nRowCount - iRow ;
      cout << endl;
    }
  }

  DisplayColumnValues();
}

CCell* CBoard::GetCell(const int& nCol, const int& nRow)
{
  return &m_pCells[nRow * m_nColCount + nCol];
}
