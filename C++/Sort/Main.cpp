#include <iostream>
#include <string>

using namespace std;

int myArray[] = {1,5,4,2,3,6,7};

void SimpleSort(int* pnElement, int nSize)
{
	int nTemp = 0;

	for (int i = 1;  i < nSize; i++)
	{
		if (pnElement[i-1] > pnElement[i])
		{
			nTemp = pnElement[i];
			pnElement[i] = pnElement[i - 1];
			pnElement[i - 1] = nTemp;
		}
	}		

	if (nSize > 2)
		SimpleSort(++pnElement, --nSize);
}

int main()
{
	SimpleSort(myArray, 7);

	for (int i =0; i < 7; i++)
	{
		cout << myArray[i] << endl;
	}	
}
