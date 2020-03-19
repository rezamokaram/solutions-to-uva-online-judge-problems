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
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
typedef pair<ll,pair<pair<ll, ll>, ll>> my;
my ndmy(ll a, ll b, ll c)
{
	my s;
	s.first = a * b;
	s.second.first.first = a;
	s.second.first.second = b;
	s.second.second = c;
	return s;
}
bool ui(my a, my b)
{
	bool one = 1, zer = 0;
	if (a.second.first.first < b.second.first.first && a.second.first.second < b.second.first.second)
		return one;
	return zer;
}
int main()
{
	int n, cs = 0;
	while (cin >> n && n)
	{
		vector<my>g;
		for (size_t i = 0; i < n; i++)
		{
			ll a[3];
			cin >> a[0] >> a[1] >> a[2];
			sort(a, a + 3);
			g.push_back(ndmy(a[0],a[1],a[2]));
			g.push_back(ndmy(a[1],a[2],a[0]));
			g.push_back(ndmy(a[0],a[2],a[1]));
		}
		sort(g.begin(), g.end());
		vector<int>lis(n * 3 + 1);
		vector<ll>sum(n * 3 + 1);
		ll mx = 0;
		for (size_t i = 0; i < g.size(); i++)
		{
			lis[i] = 1;
			sum[i] = g[i].second.second;
			mx = max(mx, sum[i]);
		}
		for (size_t i = 1; i < g.size(); i++)
		{
			my a = g[i];
			for (int j = i-1; j >= 0; j--)
			{
				my b = g[j];
				if (a.second.first.first > b.second.first.first && a.second.first.second > b.second.first.second)
				{
					if (sum[j]+a.second.second>sum[i])
					{
						sum[i] = sum[j] + a.second.second;
						mx = max(mx, sum[i]);
					}
				}
			}
		}
		cout << "Case " << ++cs << ": maximum height = " << mx << endl;
	}
}
