
#include "ChessGame.h"
#include <string>
#include <iostream>
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
}

void CChessGame::MovePiece()
{
  string strMessage;
  cout << "Please enter piece position to position:\n";
  cin >> strMessage;
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
  return true;
}

void CChessGame::DeclareWinner()
{
  // Display winning screen
}
