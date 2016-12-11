
#ifndef CHESSGAME_H
#define CHESSGAME_H

class CBoard;

class CChessGame
{
public:
  CChessGame();
  ~CChessGame();

  enum class Faction
  {
    Player1 = 0,
    Player2 = 1
  };

  void InitNewGame();
  void NewTurnPhase();
  bool IsCheckMate();
  void DeclareWinner();
  void MovePiece();

private:
  CBoard* m_pBoard;
  Faction m_eCurrentPlayer = Faction::Player1;
};

#endif
