//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<ll, ll>> vii;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAX = 100000;
typedef pair<ll, pair<int, int>> nod;
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
char li[260][260];
int n, m;
int main()
{
	for (size_t i = 0; i < 260; i++)
		for (size_t j = 0; j < 260; j++)
			li[i][j] = 'O';
	char c;
	while (cin >>c && c!='X')
	{
		if (c=='I')
		{
			int a, b;
			cin >> a >> b;
			n = b, m = a;
			for (size_t i = 0; i < b; i++)
			{
				for (size_t j = 0; j < a; j++)
				{
					li[i][j] = 'O';
				}
			}
		}
		else if (c=='C')
		{
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < m; j++)
				{
					li[i][j] = 'O';
				}
			}
		}
		else if (c=='L')
		{
			int a, b;
			char col;
			cin >> a >> b >> col;
			a--; b--;
			if(a < m && b < n)li[b][a] = col;
		}
		else if (c=='K')
		{
			int a, b, x, y;
			char col;
			cin >> a >> b >> x >> y >> col;
			a--; b--; x--; y--;
			for (size_t i = min(a,x); i <= max(a,x); i++)
			{
				for (size_t j = min(b,y); j <= max(b,y); j++)
				{
					li[j][i] = col;
				}
			}
		}
		else if (c=='H')
		{
			int a, b, y;
			char col;
			cin >> a >> b >> y >> col;
			a--; b--; y--;
			if (a > b)
				swap(a, b);
			for (size_t i = a; i <= b; i++)
			{
				li[y][i] = col;
			}
			//
			
		}
		else if (c=='V')
		{
			int x, a, b;
			char col;
			cin >> x >> a >> b >> col;
			a--; b--; x--;
			if (a>b)
				swap(a, b);
			for (size_t i = a; i <= b; i++)
			{
				li[i][x] = col;
			}
		}
		else if (c=='S')
		{
			string s;
			cin >> s;
			cout << s << endl;
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < m; j++)
				{
					cout << li[i][j];
				}
				cout << endl;
			}
		}
		else if (c=='F')
		{
			int x, y;
			char col, sc;
			bool visited[260][260] = { 0 };
			cin >> x >> y >> col;
			x--; y--;
			swap(x, y);
			sc = li[x][y];
			queue<pii>qu;
			qu.push(pii(x, y));
			while (qu.size())
			{
				pii temp = qu.front();
				qu.pop();
				if (temp.first >= n || temp.second >= m)
					continue;
				if (li[temp.first][temp.second] == sc)li[temp.first][temp.second] = col;
				else continue;
				if (temp.first)
				{
					if (!visited[temp.first-1][temp.second])
					{
						qu.push(pii(temp.first - 1, temp.second));
						visited[temp.first - 1][temp.second] = 1;
					}
				}
				if (temp.first < n)
				{
					if (!visited[temp.first + 1][temp.second])
					{
						qu.push(pii(temp.first +1, temp.second));
						visited[temp.first + 1][temp.second] = 1;
					}
				}
				if (temp.second)
				{
					if (!visited[temp.first][temp.second-1])
					{
						qu.push(pii(temp.first, temp.second - 1));
						visited[temp.first][temp.second - 1] = 1;
					}
				}
				if (temp.second < m)
				{
					if (!visited[temp.first][temp.second + 1])
					{
						qu.push(pii(temp.first, temp.second + 1));
						visited[temp.first][temp.second + 1] = 1;
					}
				}
			}
		}
		else
		{
			continue;
		}
	}
}
