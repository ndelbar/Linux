#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<long long int> nPrimes;
	
	for (int i=2; i < 100000000; ++i)
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
