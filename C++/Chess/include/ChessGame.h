
#ifndef CHESSGAME_H
#define CHESSGAME_H

class CBoard;

class CChessGame
{
public:
  CChessGame();
  ~CChessGame();

  void InitNewGame();
  void NewTurnPhase();
  bool IsCheckMate();
  void DeclareWinner();

private:
  CBoard* m_pBoard;
};

#endif
