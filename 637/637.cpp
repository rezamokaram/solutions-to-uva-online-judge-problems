#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<int> booklet;
		int lol = (((n/4)+1)*4) - n;
		if (lol==4)
		{
			lol = 0;
		}
		int temp = n + lol;
		for (size_t i = 1; i <= temp; i++)
		{
			if (i <= n)
			{
				booklet.push_back(i);
			}
			else
			{
				booklet.push_back(0);
			}
		}
		cout << "Printing order for " << n << " pages:" << endl;
		for (size_t i = 1; i <= temp/2; i++)
		{
			//check page
			if (i==temp/2)
			{
				if (booklet[i-1]==0 && booklet[i]==0)
				{
					continue;
				}
			}
			//
			if (i%2==0)
			{
				int index = i - 1;
				cout << "Sheet " << i % 2 + i / 2 << ", ";
				if (i % 2 == 1)
				{
					cout << "front";
				}
				else
				{
					cout << "back ";
				}
				cout << ": ";
				if (booklet[index] == 0)
				{
					cout << "Blank";
				}
				else
				{
					cout << booklet[index];
				}
				cout << ", ";
				int size = booklet.size() - 1;
				if (booklet[size - index] == 0)
				{
					cout << "Blank";
				}
				else
				{
					cout << booklet[size - index];
				}
				cout << endl;
			}
			else
			{
				int index = i - 1;
				cout << "Sheet " << i % 2 + i / 2 << ", ";
				if (i % 2 == 1)
				{
					cout << "front";
				}
				else
				{
					cout << "back ";
				}
				cout << ": ";
				//
				int size = booklet.size() - 1;
				if (booklet[size - index] == 0)
				{
					cout << "Blank";
				}
				else
				{
					cout << booklet[size - index];
				}
				//
				cout << ", ";
				/**/
				if (booklet[index] == 0)
				{
					cout << "Blank";
				}
				else
				{
					cout << booklet[index];
				}
				/**/
				cout << endl;
			}
		}
	}
}
