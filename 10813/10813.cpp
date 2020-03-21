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
int search(int num[], int x)
{
	for (size_t i = 0; i < 25; i++)
	{
		if (num[i]==x)
		{
			return i;
		}
	}
	return -1;
}
//
bool c[5][5];
bool col()
{
	for (size_t i = 0; i < 5; i++)
	{
		int t = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if (c[j][i]==true)
			{
				t++;
			}
			else
			{
				break;
			}
		}
		if (t==5)
		{
			return true;
		}
	}
	return false;
}
bool row()
{
	for (size_t i = 0; i < 5; i++)
	{
		int t = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if (c[i][j] == true)
			{
				t++;
			}
			else
			{
				break;
			}
		}
		if (t == 5)
		{
			return true;
		}
	}
	return false;
}
bool zed1()
{
	if (c[0][0])
	{
		if (c[1][1])
		{
			if (c[2][2])
			{
				if (c[3][3])
				{
					if (c[4][4])
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool zed2()
{
	if (c[0][4])
	{
		if (c[1][3])
		{
			if (c[2][2])
			{
				if (c[3][1])
				{
					if (c[4][0])
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int chart[5][5];
		chart[2][2] == 0;
		int arr[25];
		c[2][2] = true;
		arr[12] = 0;
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (i==2 && j==2)
				{
					continue;
				}
				cin >> chart[i][j];
				arr[i * 5 + j] = chart[i][j];
				c[i][j] = false;
			}
		}
		//
		int nm[75];
		for (size_t i = 0; i < 75; i++)
		{
			cin >> nm[i];
		}
		int win = 0;
		for (size_t i = 0; i < 75; i++)
		{
			int index = search(arr, nm[i]);
			if (index == -1)
			{
				continue;
			}
			else
			{
				int x = index / 5;
				int y = index % 5;
				c[x][y] = true;
				bool cl = col();
				bool rw = row();
				if (rw || cl || zed1() || zed2())
				{
					win = i+1;
					break;
				}
			}
		}
		//
		int ans;
		cout << "BINGO after " << win << " numbers announced" << endl;
	}
}
