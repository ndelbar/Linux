
#ifndef BOARD_H
#define BOARD_H

class CCell;

class CBoard
{

public:
	CBoard();
	~CBoard();

	void InitializeGrid();
	void DisplayCurrentBoardState();
	void DisplayColumnValues();
	CCell* GetCell(const int& nCol, const int& nRow);
  void DisplayGraphic(const char cVal, const int& nRow);

	static const int m_nRowCount;
	static const int m_nColCount;

	CCell* m_pCells;

	void SetGoodGraphics(bool bGood) { m_bGoodGraphics = bGood;}

private:
	bool m_bGoodGraphics = true;
};

#endif
