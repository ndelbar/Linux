#include "ChessGame.h"

int main()
{
  CChessGame ChessGame;

  ChessGame.InitNewGame();

  do
  {
    ChessGame.NewTurnPhase();
  }
  while(!ChessGame.IsCheckMate());

  // ChessGame.DeclareWinner();

  return 0;
}
