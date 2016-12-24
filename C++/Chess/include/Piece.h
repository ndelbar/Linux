#ifndef PIECE_H
#define PIECE_H

#include <cmath>
#include <iostream>
#include "Cell.h"

class CPiece
{
public:
        enum class Faction
        {
                Player1 = 0,
                Player2 = 1
        };


  Faction GetFaction() { return m_eFaction; }

	// creating a protected constructor so this base class cannot be declared independently of derived class.
protected:

	CPiece(Faction eFaction, CCell* pCell) :
	m_eFaction(eFaction),
	m_pParentCell(pCell)
	{}

  bool IsDiagonalMovement(CCell* pNewCell);
  bool IsHorizontalOrVerticalMovement(CCell* pNewCell);

public:

	// Pure Virtual: IsValidMove() has to be defined in the derived class
	virtual bool IsValidMove(CCell* pNewCell) = 0;

  // Pure Virtual
  virtual char GetTypeVal() = 0;

	Faction GetFaction() const { return m_eFaction; }

protected:

	Faction m_eFaction;

	CCell* m_pParentCell;
};

class CPawn : public CPiece
{
public:
  CPawn(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
      // Return is valid move?
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'P';
    else
      return 'p';
  }
};

class CRook : public CPiece
{
public:
  CRook(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
    return CPiece::IsHorizontalOrVerticalMovement(pNewCell);
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'R';
    else
      return 'r';
  }
};

class CKnight : public CPiece
{
public:
  CKnight(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
      // Return is valid move?
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'N';
    else
      return 'n';
  }
};

class CBishop : public CPiece
{
public:
  CBishop(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
    return CPiece::IsDiagonalMovement(pNewCell);
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'B';
    else
      return 'b';
  }
};

class CQueen : public CPiece
{
public:
  CQueen(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
    return IsDiagonalMovement(pNewCell) || IsHorizontalOrVerticalMovement(pNewCell);
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'Q';
    else
      return 'q';
  }
};

class CKing : public CPiece
{
public:
  CKing(Faction eFaction, CCell* pCell)
  : CPiece(eFaction, pCell)
  {}

  virtual bool IsValidMove(CCell* pNewCell)
  {
      // Return is valid move?
  }

  virtual char GetTypeVal()
  {
    if (m_eFaction == Faction::Player1)
      return 'K';
    else
      return 'k';
  }
};

#endif
