//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
const ll MAX = 9999999999;
//
bool ui(pair<int, int>a, pair<int, int>b)
{
	if (b.first == a.first)return(b.second > a.second);
	return (b.first > a.first) ? 1 : 0;
}
bool sw(bool a) { return (a) ? 0 : 1; }
int main()
{
	ll n;
	while (cin >> n && n)
	{
		int k;
		cin >> k;
		vector<bool>p(n,0),v(k,0),st(n,0);
		int visit = 0;
		p[0] = 1;
		st[0] = 1;
		vector<pair<int, int>>g(k);
		for (size_t i = 0; i < k; i++)
		{
			cin >> g[i].first >> g[i].second;
		}
		sort(g.begin(), g.end(), ui);
		while (visit < k)
		{
			for (size_t i = 0; i < k; i++)
			{
				if (v[i] == 1)continue;
				if (!st[g[i].first] && !st[g[i].second])continue;
				if (st[g[i].first])
				{
					p[g[i].second] = sw(p[g[i].first]);
					st[g[i].second] = 1;
				}
				else
				{
					p[g[i].first] = sw(p[g[i].second]);
					st[g[i].first] = 1;
				}
				visit++;
				v[i] = 1;
			}
		}
		bool ans = 1;
		for (size_t i = 0; i < k; i++)
		{
			if (p[g[i].first]==p[g[i].second])
			{
				ans = 0;
				break;
			}
		}
		if (!ans)
		{
			cout << "NOT BICOLORABLE." << endl;
		}
		else
		{
			cout << "BICOLORABLE." << endl;
		}
	}
}
