#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Grid.h"


using namespace std;

int main()
{
	srand(time(NULL));
	const int nRowCount = 20;
	const int nColCount = 50;

	CGrid myGrid(nRowCount, nColCount);

	while (true)
	{
		int nStartingNodeCount = rand() % 10 + 1;

		for (int i = 0; i < nStartingNodeCount + 1; ++i)
		{
				myGrid.AddNode(rand() % nRowCount, rand() % nColCount, rand() % 10);
		}
		//myGrid.AddNode(17,47,5);

		do
		{
			myGrid.PopulateGrid();
			myGrid.PrintGrid();
			myGrid.CalculateNextPhase();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

			if (rand()%100 > 50)
				myGrid.AddNode(rand() % nRowCount, rand() % nColCount, rand() % 10);
		}
		while(myGrid.IsNodesExist());
	}
	return 0;
}
