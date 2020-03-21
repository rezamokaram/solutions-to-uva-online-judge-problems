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
typedef pair<ll, pair<ll, ll>> my;
my nc(ll a, ll b, ll c)
{
	my s;
	s.first = a;
	s.second.first = b;
	s.second.second = c;
	return s;
}
//
int LIS(const vector<int> &d)
{
	vector<int>lis;
	for (size_t i = 0; i < d.size(); i++)
	{
		int pos = upper_bound(lis.begin(), lis.end(), d[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(d[i]);
		else
			lis[pos] = min(lis[pos], d[i]);
	}
	return lis.size();
}
//
//
int main()
{
	ll a, b, c = 0;
	vector<my>list;
	while (cin >> a >> b)
		list.push_back(nc(a, b, c++));
	sort(list.begin(), list.end());
	vector<int>lis(list.size()), par(list.size());
	int mx = 0, inm = 0;
	for (int i = 0; i < list.size(); i++)
	{
		lis[i] = 1; par[i] = i;
		for (int j = i-1; j >= 0; j--)
		{
			if (list[i].first > list[j].first && list[i].second.first < list[j].second.first)
			{
				if (lis[j]+1>lis[i])
				{
					lis[i] = lis[j] + 1;
					par[i] = j;
					if (lis[i] > mx)
					{
						mx = lis[i];
						inm = i;
					}
				}
			}
		}
	}
	vector<int>ans;
	ans.push_back(list[inm].second.second + 1);
	while (1)
	{
		inm = par[inm];
		ans.push_back(list[inm].second.second + 1);
		if (inm == par[inm])
			break;
	}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << endl;
}
