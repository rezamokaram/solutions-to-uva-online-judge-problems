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
const ll MAX = 100000;
typedef pair<double, pair<int, int>> nod;
typedef pair<ll, ll> no;
//
const int zero = 1010;
bool ui(nod a, nod b) { return (b.first > a.first); }
double compt(no a, no b)
{
	ll x = llabs(a.first - b.first);
	ll y = llabs(a.second - b.second);
	double res = (y*y) + (x*x);
	res = sqrt(res);
	return res;
}
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
int main()
{
	int n,cs=0;
	while (cin >> n && n)
	{
		pr.clear();
		vector<no>p(n);
		vector<nod>g;
		for (int i = 0; i < n; i++)
		{
			pr.push_back(i);
			cin >> p[i].first >> p[i].second;
			for (int j = 0; j < i; j++)
			{
				nod t;
				t.first = compt(p[i], p[j]);
				t.second.first = i;
				t.second.second = j;
				g.push_back(t);
			}
		}
		sort(g.begin(), g.end(), ui);
		vector<nod>mst;
		double sum = 0;
		for (size_t i = 0; i < g.size(); i++)
			if (getp(g[i].second.first) != getp(g[i].second.second))
			{
				pr[getp(g[i].second.second)] = getp(g[i].second.first);
				mst.push_back(g[i]);
			}
		queue<int>ss;
		ss.push(0);
		vector<vector<nod>>buk(n);
		for (size_t i = 0; i < mst.size(); i++)
		{
			buk[mst[i].second.first].push_back(mst[i]);
			buk[mst[i].second.second].push_back(mst[i]);
		}
		vector<bool>vis(n,0);
		vector<int>par(n);
		vector<double>ans(n);
		while (ss.size())
		{
			int now = ss.front();
			ss.pop();
			vis[now] = 1;
			for (size_t i = 0; i < buk[now].size(); i++)
			{
				int bfs = now == buk[now][i].second.first ? buk[now][i].second.second : buk[now][i].second.first;
				if (!vis[bfs])
				{
					vis[bfs] = 1;
					par[bfs] = now;
					ans[bfs] = max(ans[now], buk[now][i].first);
					ss.push(bfs);
				}
			}
		}
		cout << "Scenario #" << ++cs << endl << "Frog Distance = " << fixed << setprecision(3) << ans[1] << endl << endl;
	}
}
/*
Scenario #1
Frog Distance = 5.000

*/
