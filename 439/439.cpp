#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
//typedef long long int ll;
typedef long long unsigned int llu;
//
vector<vector<bool>>list(8);
vector<vector<bool>>ll(8);
void f()
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			list[i].push_back(0);
			ll[i].push_back(0);
		}
	}
}
void run() 
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (list[i][j]==1)
			{
				if (i>1 && j>0)
				{
					ll[i - 2][j - 1] = 1;
				}
				if (i>1 && j<7)
				{
					ll[i - 2][j + 1] = 1;
				}
				if (i < 6 && j > 0)
				{
					ll[i + 2][j - 1] = 1;
				}
				if (i < 6 && j < 7)
				{
					ll[i + 2][j + 1] = 1;
				}
				//
				if (i > 0 && j > 1)
				{
					ll[i - 1][j - 2] = 1;
				}
				if (i < 7 && j > 1)
				{
					ll[i + 1][j - 2] = 1;
				}
				if (i > 0 && j < 6)
				{
					ll[i - 1][j + 2] = 1;
				}
				if (i < 7 && j < 6)
				{
					ll[i + 1][j + 2] = 1;
				}
			}
		}
	}
}
int main()
{
	string a, b;
	f();
	while (cin >> a >> b)
	{
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				list[i][j] = 0;
				ll[i][j] = 0;
			}
		}
		int xa = a[0] - 'a';
		int ya = a[1] - '1';
		int xb = b[0] - 'a';
		int yb = b[1] - '1';
		ll[xa][ya] = 1;
		list[xa][ya] = 1;
		int moves = 0;
		while (!ll[xb][yb])
		{
			moves++;
			run();
			list = ll;
		}
		cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves." << endl;
	}
}
