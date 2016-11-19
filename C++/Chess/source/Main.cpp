#include "ChessGame.h"

int main()
{
  CChessGame ChessGame;

  ChessGame.InitNewGame();

  do
  {
    // ChessGame.NextTurnPhase();
  }
  while(!ChessGame.IsCheckMate());

  // ChessGame.DeclareWinner();

  return 0;
}
