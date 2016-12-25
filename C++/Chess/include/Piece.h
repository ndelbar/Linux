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

  void SetParentCell(CCell* pCell);

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

  bool m_bFirstMove = true;

  virtual bool IsValidMove(CCell* pNewCell)
  {
    bool bMoveDown = m_eFaction == Faction::Player1;
    bool bFirstMove = m_bFirstMove;
    int nDiffValueExpected = 1;

    m_bFirstMove = false;

    if (m_eFaction == Faction::Player2)
    {
      nDiffValueExpected = -1;
    }

    if (pNewCell->GetPiece())
    {
      if ((pNewCell->GetRow() - m_pParentCell->GetRow()) == nDiffValueExpected)
      {
        if (std::abs(pNewCell->GetColumn() - m_pParentCell->GetColumn() == 1))
        {
          return true;
        }
      }
    }
    else
    {
      if (pNewCell->GetRow() - m_pParentCell->GetRow() == nDiffValueExpected)
      {
        return true;
      }

      if (bFirstMove && (pNewCell->GetRow() - m_pParentCell->GetRow()) == (nDiffValueExpected * 2))
      {
        return true;
      }
    }

    m_bFirstMove = bFirstMove;
    return false;
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
      return (std::abs(pNewCell->GetRow() - m_pParentCell->GetRow()) == 2 && std::abs(pNewCell->GetColumn() - m_pParentCell->GetColumn()) == 1) ||
             (std::abs(pNewCell->GetRow() - m_pParentCell->GetRow()) == 1 && std::abs(pNewCell->GetColumn() - m_pParentCell->GetColumn()) == 2);
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
      return std::abs(pNewCell->GetRow() - m_pParentCell->GetRow()) + std::abs(pNewCell->GetColumn() - m_pParentCell->GetColumn()) == 1;
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
