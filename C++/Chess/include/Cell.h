#ifndef CLASS_H
#define CLASS_H

class CPiece;

class CCell
{
public:
  CCell();
  ~CCell();

  void SetPosition(const int& nRow, const int& nCol);
  void AddPiece(const char& cPiece);
  void RemovePiece();
  void TransferPiece(CCell* pNewCell);
  void SetPiece(CPiece* pPiece);
  CPiece* GetPiece();

  const int GetRow() { return m_nRow; }
  const int GetColumn() { return m_nCol; }

  void SetRow(const int& nRow) { m_nRow = nRow; }
  void SetColumn(const int& nColumn) { m_nCol = nColumn; }

private:
  CPiece* m_pPiece = NULL;
  int m_nRow;
  int m_nCol;
};

#endif
