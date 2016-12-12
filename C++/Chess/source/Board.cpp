#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Piece.h"

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

      //cout << cVal;

      if (cVal != '.');
      {
        m_pCells[iRow * m_nColCount + iCol].AddPiece(cVal);
      }
    }
    //cout << endl;
  }
}

void CBoard::DisplayColumnValues()
{
  cout << endl;

  cout << "  ";

  for(char iCol = 0; iCol < m_nColCount; ++iCol)
  {
    cout << (char)('a' + iCol);
  }

  cout << endl << endl;
}

void CBoard::DisplayCurrentBoardState()
{
  DisplayColumnValues();

  for (int iRow = 0; iRow < m_nRowCount; ++iRow)
  {
    cout << m_nRowCount - iRow << " ";
    for(int iCol = 0; iCol < m_nColCount; ++iCol)
    {
      CPiece* pPiece = m_pCells[iRow * m_nColCount + iCol].GetPiece();

      if (pPiece)
        cout << pPiece->GetTypeVal();
      else
        cout << ".";
    }
    cout << " " << m_nRowCount - iRow ;
    cout << endl;
  }

  DisplayColumnValues();
}
