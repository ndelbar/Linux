
#include "ChessGame.h"
#include "Board.h"

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
  m_pBoard->DisplayCurrentBoardState();
}

void CChessGame::NewTurnPhase()
{
  // Display Current Board State;

  // Get Input for next players move.
  // See if move is valid. (CPiece)

  // Make sure player didn't put self in check.
}

bool CChessGame::IsCheckMate()
{
  // See if a check mate exists.

  // If so, declare winner.

  // returning true so there's no infinite loop until logic is implemented.
  return true;
}

void CChessGame::DeclareWinner()
{
  // Display winning screen
}
