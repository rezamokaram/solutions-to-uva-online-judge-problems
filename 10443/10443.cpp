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
	int tc;
	cin >> tc;
	bool f = false;
	while (tc--)
	{
		if (f)
		{
			cout << endl;
		}
		f = true;
		int r, c, n;
		vector<string>list;
		vector<string>nlist;
		cin >> r >> c >> n;
		for (size_t i = 0; i < r; i++)
		{
			string temp;
			cin >> temp;
			list.push_back(temp);
			nlist.push_back(temp);
		}
		while (n--)
		{
			for (size_t i = 0; i < r; i++)
			{
				for (size_t j = 0; j < c; j++)
				{
					if (list[i][j] == 'R')
					{
						if (i > 0)
						{
							if (list[i - 1][j] == 'P')
							{
								nlist[i][j] = 'P';
								continue;
							}
						}
						if (i < r - 1)
						{
							if (list[i + 1][j] == 'P')
							{
								nlist[i][j] = 'P';
								continue;
							}
						}
						if (j > 0)
						{
							if (list[i][j - 1] == 'P')
							{
								nlist[i][j] = 'P';
								continue;
							}
						}
						if (j < c - 1)
						{
							if (list[i][j + 1] == 'P')
							{
								nlist[i][j] = 'P';
								continue;
							}
						}
					}
					else if (list[i][j] == 'S')
					{
						if (i > 0)
						{
							if (list[i - 1][j] == 'R')
							{
								nlist[i][j] = 'R';
								continue;
							}
						}
						if (i < r - 1)
						{
							if (list[i + 1][j] == 'R')
							{
								nlist[i][j] = 'R';
								continue;
							}
						}
						if (j > 0)
						{
							if (list[i][j - 1] == 'R')
							{
								nlist[i][j] = 'R';
								continue;
							}
						}
						if (j < c - 1)
						{
							if (list[i][j + 1] == 'R')
							{
								nlist[i][j] = 'R';
								continue;
							}
						}
					}
					else// 'p'
					{
						if (i > 0)
						{
							if (list[i - 1][j] == 'S')
							{
								nlist[i][j] = 'S';
								continue;
							}
						}
						if (i < r - 1)
						{
							if (list[i + 1][j] == 'S')
							{
								nlist[i][j] = 'S';
								continue;
							}
						}
						if (j > 0)
						{
							if (list[i][j - 1] == 'S')
							{
								nlist[i][j] = 'S';
								continue;
							}
						}
						if (j < c - 1)
						{
							if (list[i][j + 1] == 'S')
							{
								nlist[i][j] = 'S';
								continue;
							}
						}
					}
				}
			}
			for (size_t i = 0; i < r; i++)
			{
				for (size_t j = 0; j < c; j++)
				{
					list[i][j] = nlist[i][j];
				}
			}
		}
		for (size_t i = 0; i < r; i++)
		{
			cout << list[i] << endl;
		}
	}
}
