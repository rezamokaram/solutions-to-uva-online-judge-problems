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
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<pair<int,int>> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
const vi vvi;
vector<vector<pair<int, int>>>parent;
void sset(int n)
{
	parent.clear();
	for (size_t i = 0; i < n + 1; i++)
	{
		parent.push_back(vvi);
		for (size_t j = 0; j < n + 1; j++)
			parent[i].push_back(pair<int, int>(i, j));
	}
}
pair<int,int> gp(int x,int y)
{
	if (parent[x][y].first==x && parent[x][y].second==y)
	{
		return parent[x][y];
	}
	return parent[x][y] = gp(parent[x][y].first, parent[x][y].second);
}
bool isch(char a)
{
	return (a == 'L' || a == 'W');
}
int xc[6] = { 0 , 0 , 1 , 1 ,-1 ,-1 };
int yc[6] = { 1 ,-1 , 1 , 0 , 0 ,-1 };
int main()
{
	int n, cs = 0;
	while (cin >> n && n)
	{
		vector<string>li(n);
		for (size_t i = 0; i < n; i++)
			cin >> li[i];
		sset(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				pair<int, int> f = gp(i, j);
				for (int z = 0; z < 6; z++)
				{
					if (i + xc[z] < 0 || i + xc[z] >= n || j + yc[z] < 0 || j + yc[z] >= n)
						continue;
					if (li[i][j] != li[i + xc[z]][j + yc[z]])
						continue;
					pair<int, int>sec = gp(i + xc[z], j + yc[z]);
					if (sec!=f)
					{
						parent[sec.first][sec.second] = f;
					}
				}
			}
		}
		bool f = 1;// f==1+>>W
		set<pair<int, int>>roots;
		for (int i = 0; i < li[0].size(); i++)
		{
			if(li[0][i]=='b')roots.emplace(gp(0, i));
		}
		for (size_t i = 0; i < n; i++)
		{
			if (li[n-1][i]=='b')
			{
				if (binary_search(roots.begin(), roots.end(), gp(n - 1, i)))
				{
					f = 0;
					break;
				}
			}
		}
		if (f)
			cout << ++cs << " W" << endl;
		else
			cout << ++cs << " B" << endl;
	}
}
