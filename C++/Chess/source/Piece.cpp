#include "Piece.h"

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
