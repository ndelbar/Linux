#include <iostream>

using namespace std;

void DispMissingChars(const string& strMessage)
{
	// Since we're dealing w/ only lower case letters, we can fit the
	// boolean array into a 32 bit int. In all cases, this will be the 
	// most memory efficient, and fast performance.
	int b32UsedCharacters = 0;

	const int nMessageLength = strMessage.length();
	
	for (int iChar = 0; iChar < nMessageLength; ++iChar)
	{
		// For each char in strMessage, if the lowercase version of 
		// the current char is between 'a' and 'z' use a bitwise Or 
		// to store the appropriate bit to true, signalling 
		// that character exists
		const char cCurrent = tolower(strMessage[iChar]);
		
		if (cCurrent >= 'a' && cCurrent <= 'z')
			b32UsedCharacters |= (1 << (cCurrent - 'a'));
	}

	// First, check if all characters are accounted for. This is equivalent 
	// to 00000011111111111111111111111111 which is 67108863
	if (b32UsedCharacters == 67108863)
	{
		cout << "NULL";
	}
	else
	{
		for (char iChar = 'a'; iChar <= 'z'; ++iChar)
		{
			// For each value in the alphabet, display the 
			// characters that were not present in the strMessage
			// in alphabetical order.
			if (!(b32UsedCharacters & (1 << (iChar - 1))))
				cout << iChar;
		}
	}
}

int main()
{
	//string strMessage = "A quick brown fox jumps over the lazy dog";
	string strMessage = "A slow yellow fox crawls under the proactive dog";
	//string strMessage = "";
	//string strMessage = "abc\0def";

	DispMissingChars(strMessage);
}
