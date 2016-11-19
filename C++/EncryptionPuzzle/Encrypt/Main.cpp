#include <iostream>
#include <iomanip>

using namespace std;

void DisplayBits(const int& nVal)
{
  for(int i = 31; i >= 0; --i)
  {
    cout << ((nVal >> i) & 1);
  }
}

int main()
{
  //32
  //b0c152f9 ebf2831f
  //46508fb7 6677e201

  //16
  //b0c152f9
  //         11045541

  int size;
  cout << "Input Size: ";
  cin >> size;

  unsigned int* a = new unsigned int[size / 16]; // <- input tab to encrypt
  unsigned int* b = new unsigned int[size / 16]; // <- output tab
 
  cout << "Input Hex " << size / 16 << " times:";
  for (int i = 0; i < size / 16; i++) {   // Read size / 16 integers to a
    cin >> hex >> a[i];
  }

  for (int i = 0; i < size / 16; i++) {   // Write size / 16 zeros to b
    b[i] = 0;
  }	
 
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) 
    {
      b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) &
		       (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation

      int one = i+j;
      int two = one % 32;
      int three = a[j/32 + size/32];
      int four = three >> (j % 32) & 1;
      int five = four << two;
      int six = a[i/32] >> a[i/32] >> (i%32);
      int seven = six & four;
      int eight = b[(i + j) / 32] ^= seven;

      cout << "++++++" << endl << one << endl << two << endl << three << endl << four << endl <<  five << endl <<  six << endl << seven << endl << eight << endl;


    }
 
  for(int i = 0; i < size / 16; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << setfill('0') << setw(8) << hex << b[i];       // print result
    //cout << b[i];
  }
  cout << endl;

  for (int i = size - 1; i >= 0 ; --i)
	for (int j = size - 1; j >= 0; --j)
  {
	cout << "------" << endl;
  }

 /* 
    Good luck humans     
 */
  return 0;
}
