
#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <string>

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
  void DisplayTitle();
  void DisplayOptions();

private:
  bool ParseMoveMessage(const std::string& strMessage, int& nCol1, int& nRow1, int& nCol2, int& nRow2);
  bool EvaluateAndMovePiece(const int& nCol1, const int& nRow1, const int& nCol2, const int& nRow2);

private:
  CBoard* m_pBoard;
  Faction m_eCurrentPlayer = Faction::Player1;
};

#endif
