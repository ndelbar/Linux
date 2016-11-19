#include <string>
#include <iostream>

using namespace std;

string myTokenize(const string& strNumberList, const char& cToken, int& nCurPos)
{
	const int nStartPos = nCurPos;

	nCurPos = strNumberList.find(cToken, nCurPos);

	if (nCurPos == -1)
		return strNumberList.substr(nStartPos);
	else
		return strNumberList.substr(nStartPos, nCurPos++ - nStartPos);
}

void myPrintNumber(const string& strNumber)
{
	if (strNumber == "one")
		cout << 1;
	else if (strNumber == "two")
		cout << 2;
	else if (strNumber == "three")
		cout << 3;
	else if (strNumber == "four")
		cout << 4;
	else if (strNumber == "five")
		cout << 5;
	else if (strNumber == "six")
		cout << 6;
	else if (strNumber == "seven")
		cout << 7;
	else if (strNumber == "eight")
		cout << 8;
	else if (strNumber == "nine")
		cout << 9;
	else if (strNumber == "zero")
		cout << 0;
	else
	{
		cout << '?';
	}
}

int main()
{
	string strNumberList = "one;fish;two;fish;three;four;five;six;seven;eight;nine;zero";

	int nCurPos = 0;
	string strNumber;

	while (nCurPos != -1)
	{
		strNumber = myTokenize(strNumberList, ';', nCurPos);

		myPrintNumber(strNumber);
	}
}
