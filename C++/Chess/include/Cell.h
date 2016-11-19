
class CPiece;

class CCell
{
public:
  CCell();
  ~CCell();

  void SetPosition(const int& nRow, const int& nCol);
  void AddPiece(const char& cPiece);
  void RemovePiece();
  CPiece* GetPiece();

private:
  CPiece* m_pPiece;
  int m_nRow;
  int m_nCol;
};
