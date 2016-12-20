#include <stdio.h>
#include <ctype.h>

#include "Cell.h"
#include "Piece.h"

CCell::CCell()
: m_pPiece(NULL)
{

}

CCell::~CCell()
{
  RemovePiece();
}

CPiece* CCell::GetPiece()
{
  return m_pPiece;
}

void CCell::SetPosition(const int& nRow, const int& nCol)
{
  m_nRow = nRow;
  m_nCol = nCol;
}

void CCell::AddPiece(const char& cPiece)
{
  CPiece::Faction eFaction = CPiece::Faction::Player1;

  if (cPiece >= 'a' && cPiece <= 'z')
    eFaction = CPiece::Faction::Player2;

  const char cType = toupper(cPiece);

  switch(cType)
  {
    case 'P':
      m_pPiece = new CPawn(eFaction, this);
      break;
    case 'R':
      m_pPiece = new CRook(eFaction, this);
      break;
    case 'N':
      m_pPiece = new CKnight(eFaction, this);
      break;
    case 'B':
      m_pPiece = new CBishop(eFaction, this);
      break;
    case 'Q':
      m_pPiece = new CQueen(eFaction, this);
      break;
    case 'K':
      m_pPiece = new CKing(eFaction, this);
      break;
  }

}

void CCell::RemovePiece()
{
  if (m_pPiece)
  {
    delete m_pPiece;
    m_pPiece = NULL;
  }
}
