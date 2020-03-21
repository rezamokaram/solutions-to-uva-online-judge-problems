#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	
	string n;
	while (cin >> n)
	{
		int len = n.length();
		for (size_t i = 0; i < len; i++)
		{
			if (n[i]=='A' || n[i]=='B' || n[i]=='C')
			{
				cout << 2;
			}
			else if (n[i] == 'D' || n[i] == 'E' || n[i] == 'F')
			{
				cout << 3;
			}
			else if (n[i] == 'G' || n[i] == 'H' || n[i] == 'I')
			{
				cout << 4;
			}
			else if (n[i] == 'J' || n[i] == 'K' || n[i] == 'L')
			{
				cout << 5;
			}
			else if (n[i] == 'M' || n[i] == 'N' || n[i] == 'O')
			{
				cout << 6;
			}
			else if (n[i] == 'P' || n[i] == 'Q' || n[i] == 'R' || n[i] == 'S')
			{
				cout << 7;
			}
			else if (n[i] == 'T' || n[i] == 'U' || n[i] == 'V')
			{
				cout << 8;
			}
			else if (n[i] == 'W' || n[i] == 'X' || n[i] == 'Y' || n[i] == 'Z')
			{
				cout << 9;
			}
			else
			{
				cout << n[i];
			}
		}
		cout << endl;
	}
}
