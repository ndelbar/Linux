#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<long long int> nPrimes;

	nPrimes.insert(2);
	
	for (int i = 3; i < 100000000; i += 2)
	{
		bool bDivisible = false;
		
		for (auto iPrime: nPrimes)
		{
			if (i % iPrime == 0)
			{
				bDivisible = true;
				break;
			}
		}

		if (!bDivisible)
		{
			nPrimes.insert(i);	
			cout << i << endl;
		}
	}
	
	return 0;
}
