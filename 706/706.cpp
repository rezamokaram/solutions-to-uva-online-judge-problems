#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;

int main()
{
	int a;
	string b;
	bool f = false;
	while (cin >> a >> b)
	{
		if (a==0)
		{
			break;
		}
		if (f==true)
		{
			//cout << endl;
		}
		f = true;
		char a0[] = " - | |   | | - \0";
		char a1[] = "     |     |   \0";
		char a2[] = " -   | - |   - \0";
		char a3[] = " -   | -   | - \0";
		char a4[] = "   | | -   |   \0";
		char a5[] = " - |   -   | - \0";
		char a6[] = " - |   - | | - \0";
		char a7[] = " -   |     |   \0";
		char a8[] = " - | | - | | - \0";
		char a9[] = " - | | -   | - \0";
		vector<string>list;
		int size = b.length();
		for (size_t i = 0; i < size; i++)
		{
			if (b[i]=='0')
			{
				list.push_back(a0);
			}
			else if (b[i] == '1')
			{
				list.push_back(a1);
			}
			else if (b[i] == '2')
			{
				list.push_back(a2);
			}
			else if (b[i] == '3')
			{
				list.push_back(a3);
			}
			else if (b[i] == '4')
			{
				list.push_back(a4);
			}
			else if (b[i] == '5')
			{
				list.push_back(a5);
			}
			else if (b[i] == '6')
			{
				list.push_back(a6);
			}
			else if (b[i] == '7')
			{
				list.push_back(a7);
			}
			else if (b[i] == '8')
			{
				list.push_back(a8);
			}
			else //if (b[i] == '9')
			{
				list.push_back(a9);
			}
		}
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t d = 0; d < a; d++)
			{
				for (size_t z = 0; z < size; z++)
				{
					for (size_t j = i * 3; j < (i * 3) + 3; j++)
					{
						for (size_t q = 0; q < 1+(a-1); q++)
						{
							cout << list[z][j];
							if (j%3==0 || j%3==2)
							{
								break;
							}
							if (i % 2 == 1 && list[z][j]=='|')
							{
								break;
							}
						}
					}
					if (z!=size-1)
					{
						cout << " ";
					}
					
				}
				cout << endl;
				if (i%2==0)
				{
					break;
				}
			}
		}
		cout << endl;
	}
}
