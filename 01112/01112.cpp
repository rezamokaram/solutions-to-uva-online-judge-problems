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
	ll v, des;
	edge(ll vv, ll dd)
	{
		v = vv, des = dd;
	}
	bool operator >(const edge & sec) const
	{
		return(v > sec.v);
	}
};
//
int main()
{
	ll tc;
	cin >> tc;
	bool ff = 0;
	while (tc--)
	{
		if (ff)cout << endl;
		ff = 1;
		ll n, e, t, m;
		cin >> n >> e >> t >> m;
		vector<ll>vertex(n+2, 0);
		vector<bool>vis(n + 2);
		for (size_t i = 0; i < n+1; i++)
		{
			vis[i] = 0;
			vertex[i] = n + 1;
		}
		vector<vector<edge>>li(n+2);
		for (size_t i = 0; i < m; i++)
		{
			ll a, b, v;
			cin >> a >> b >> v;
			li[b].push_back(edge(v, a));
		}
		priority_queue<ll, vector<ll>, greater<ll>>pq;
		pq.push(e);
		vis[e] = 1; 
		vertex[e] = 0;
		llu ans = 1;
		while (!pq.empty())
		{
			ll u = pq.top();
			pq.pop();
			for (size_t i = 0; i < li[u].size(); i++)
			{
				if (vertex[u] + li[u][i].v < vertex[li[u][i].des] && vertex[u] + li[u][i].v <= t)
				{
					vertex[li[u][i].des] = vertex[u] + li[u][i].v;
					if (vis[li[u][i].des]==0)
					{
						vis[li[u][i].des] = 1;
						ans++;
					}
					pq.push(li[u][i].des);
				}
			}
		}
		cout << ans << endl;
	}
}
