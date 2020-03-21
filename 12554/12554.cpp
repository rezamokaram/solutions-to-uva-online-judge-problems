#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	int tc;
	while (cin >> tc)
	{
		vector<string> list;
		for (size_t i = 0; i < tc; i++)
		{
			string a;
			cin >> a;
			list.push_back(a);
		}
		int temp = (tc / 16);
		if (tc%16>0)
		{
			temp++;
		}
		for (size_t j = 0; j < temp; j++)
		{
			for (size_t i = 0; i < 16; i++)
			{
				if (i % 4 == 0)
				{
					cout << list[(i+(j*16)) % tc] << ": Happy" << endl;
				}
				else if (i % 4 == 1)
				{
					cout << list[(i + (j * 16)) % tc] << ": birthday" << endl;
				}
				else if (i % 4 == 2)
				{
					cout << list[(i + (j * 16)) % tc] << ": to" << endl;
				}
				else
				{
					cout << list[(i + (j * 16)) % tc] << ": ";// << endl;
					if (i == 11)
					{
						cout << "Rujia" << endl;
					}
					else
					{
						cout << "you" << endl;
					}
				}
			}
		}
	}
}
