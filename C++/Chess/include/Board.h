
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

	static const int m_nRowCount;
	static const int m_nColCount;

	CCell* m_pCells;
};

#endif
