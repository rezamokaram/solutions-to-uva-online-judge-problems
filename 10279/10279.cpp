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
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<string>list;
bool f = 0;
int nb(int x, int y)
{
	int res = 0;
	if (list[x][y]=='*')
	{
		f = 1;
		//return -1;
	}
	if (x)
	{
		if (list[x - 1][y] == '*')
		{
			res++;
		}
		if (y)
		{
			if (list[x - 1][y - 1] == '*')
			{
				res++;
			}
		}
		if (y < list.size() - 1)
		{
			if (list[x - 1][y + 1] == '*')
			{
				res++;
			}
		}
	}
	if (x < list[x].size() - 1)
	{
		if (list[x + 1][y] == '*')
		{
			res++;
		}
		if (y)
		{
			if (list[x + 1][y - 1] == '*')
			{
				res++;
			}
		}
		if (y < list.size() - 1)
		{
			if (list[x + 1][y + 1] == '*')
			{
				res++;
			}
		}
	}
	if (y)
	{
		if (list[x][y - 1] == '*')
		{
			res++;
		}
	}
	if (y < list.size() - 1)
	{
		if (list[x][y + 1] == '*')
		{
			res++;
		}
	}
	return res;
}
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		list.clear();
		f = 0;
		int n;
		cin >> n;
		vector<string>m(n);
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			list.push_back(temp);
		}
		for (int i = 0; i < n; i++) { cin >> m[i]; }
		vector<vector<int>>num(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m[i].size(); j++)
			{
				if (m[i][j]=='x')
				{
					num[i].push_back(nb(i, j));
				}
				else
				{
					num[i].push_back(0);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m[i].size(); j++)
			{
				if (f)
				{
					if (list[i][j]=='*')
					{
						cout << '*';
					}
					else if (m[i][j] == 'x')
					{
						cout << num[i][j];
					}
					else
					{
						cout << '.';
					}
				}
				else
				{
					if (m[i][j] == 'x')
					{
						cout << num[i][j];
					}
					else
					{
						cout << '.';
					}
				}
			}
			cout << endl;
		}
		if (tc)
		{
			cout << endl;
		}
	}
}
