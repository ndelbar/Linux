
#include "ChessGame.h"
#include <iostream>
#include "Board.h"
#include "Cell.h"
#include "Piece.h"

using namespace std;

CChessGame::CChessGame()
{
  m_pBoard = new CBoard;
}

CChessGame::~CChessGame()
{
  delete m_pBoard;
}

void CChessGame::InitNewGame()
{
  m_pBoard->InitializeGrid();
}

void CChessGame::MovePiece()
{
  string strMessage;
  int nCol1, nRow1, nCol2, nRow2;

  do
  {
    cout << "Please enter piece position to position:\n";
    cin >> strMessage;
  }
  while(!ParseMoveMessage(strMessage, nCol1, nRow1, nCol2, nRow2));

  EvaluateAndMovePiece(nCol1, nRow1, nCol2, nRow2);
}

void CChessGame::NewTurnPhase()
{
  // Display Current Board State;
  m_pBoard->DisplayCurrentBoardState();

  // Get Input for next players move.
  MovePiece();

  // Make sure player didn't put self in check.
}

bool CChessGame::IsCheckMate()
{
  // See if a check mate exists.

  // If so, declare winner.

  // returning true so there's no infinite loop until logic is implemented.
  return false;
}

void CChessGame::DeclareWinner()
{
  // Display winning screen
}

bool CChessGame::ParseMoveMessage(const string& strMessage, int& nCol1, int& nRow1, int& nCol2, int& nRow2)
{
  bool bValidMove = false;

  if (strMessage.length() == 4)
  {
    nCol1 = strMessage[0] - 'a';
    nRow1 = 7 - (strMessage[1] - '1');
    nCol2 = strMessage[2] - 'a';
    nRow2 = 7 - (strMessage[3] - '1');

    //cout << nCol1 << " " << nRow1 << " " << nCol2 << " "<< nRow2 << endl;

    if (nCol1 < 0 || nCol1 >= 8)
      cout << "First column not valid";
    else if (nCol2 < 0 || nCol2 >= 8)
      cout << "Second column not valid";
    else if (nRow1 < 0 || nRow1 >= 8)
      cout << "First row not valid";
    else if (nRow2 < 0 || nRow2 >= 8)
      cout << "Second row not valid";
    else
      bValidMove = true;
  }
  else
  {
    cout << "Format must be four characters no spaces" << endl;
  }

  return bValidMove;
}

bool CChessGame::EvaluateAndMovePiece(const int& nCol1, const int& nRow1, const int& nCol2, const int& nRow2)
{
  CCell* pCellOriginal = m_pBoard->GetCell(nCol1, nRow1);
  CCell* pCellNew = m_pBoard->GetCell(nCol2, nRow2);

  if (pCellNew && pCellOriginal && pCellOriginal->GetPiece())
  {
    if (pCellOriginal->GetPiece()->IsValidMove(pCellNew))
    {
      if (pCellNew->GetPiece())
        pCellNew->RemovePiece();

      pCellNew->AddPiece(pCellOriginal->GetPiece()->GetTypeVal());
      pCellOriginal->RemovePiece();
    }
    else
    {
      cout << "Invalid move" << endl;
    }
  }

  return true;
}
