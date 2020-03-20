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
using namespace std;
//
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 9999999999 + 1;
typedef pair<ll, pair<int, int>> edg;
struct edge
{
	ll v, r, c;
	edge(ll vv, ll rr, ll cc)
	{
		v = vv, r = rr, c = cc;
	}
	bool operator >(const edge & sec) const
	{
		return(v > sec.v);
	}
};
//
int cx[4] = { 0,0,-1,1 };
int cy[4] = { -1,1,0,0 };
int main()
{
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll n, m;
		cin >> n >> m;
		vector < vector < ll >> li(n), maze(n);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				ll a;
				cin >> a;
				li[i].push_back(a);
				maze[i].push_back(llm);
			}
		}
		maze[0][0] = li[0][0];
		edge u(0, 0, 0);
		priority_queue<edge, vector<edge>, greater<edge>>pq;
		pq.push(u);
		while (pq.size())
		{
			u = pq.top();
			pq.pop();
			for (size_t i = 0; i < 4; i++)
			{
				int r = u.r + cx[i];
				int c = u.c + cy[i];
				if (c < 0 || c >= m || r < 0 || r >= n)
					continue;
				if (maze[u.r][u.c]+li[r][c]<maze[r][c])
				{
					maze[r][c] = maze[u.r][u.c] + li[r][c];
					pq.push(edge(maze[r][c], r, c));
				}
			}
		}
		cout << maze[n - 1][m - 1] << endl;
	}
}
