#include "Piece.h"
#include <iostream>

using namespace std;

bool CPiece::IsDiagonalMovement(CCell* pNewCell)
{
  if (std::abs(m_pParentCell->GetRow() - pNewCell->GetRow()) == std::abs(m_pParentCell->GetColumn() - pNewCell->GetColumn()))
    return true;

  return false;
}

bool CPiece::IsHorizontalOrVerticalMovement(CCell* pNewCell)
{
  if (m_pParentCell->GetRow() == pNewCell->GetRow())
    return true;
  else if (m_pParentCell->GetColumn() == pNewCell->GetColumn())
    return true;

  return false;
}

void CPiece::SetParentCell(CCell* pCell)
{
  m_pParentCell = pCell;
}
