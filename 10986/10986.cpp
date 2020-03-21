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
const ll MAX = 100000;
const llu llm = 2 * 100000 * 9999999999;
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
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		ll n, m;
		cin >> n >> m;
		int fer, sec;
		cin >> fer >> sec;
		vector<vector<pii>>li(n);
		vector<llu>la(n), na(n);
		vector<bool>ff(n, 0);
		for (ll i = 0; i < n; i++)
		{
			na[i] = llm;
		}
		for (ll i = 0; i < m; i++)
		{
			int a, b;
			llu val;
			cin >> a >> b >> val;
			if (a == b)continue;
			li[a].push_back(pii(val, b));
			li[b].push_back(pii(val, a));
		}
		na[fer] = 0;
		queue<ll>qu;
		qu.push(fer);
		bool f = 1;
		while (qu.size())
		{
			ll index = qu.front();
			qu.pop();
			if ((ff[index] && la[index] == na[index]) || index == sec)continue;
			for (ll i = 0; i < li[index].size(); i++)
			{
				if (li[index][i].second == sec)f = 0;
				if (li[index][i].first + na[index] < na[li[index][i].second])
				{
					na[li[index][i].second] = na[index] + li[index][i].first;
					qu.push(li[index][i].second);
				}
			}
			la[index] = na[index];
			ff[index] = 1;
		}
		cout << "Case #" << ++cs << ": ";
		if (f && fer!=sec)//na[n-1]==llm)
			cout << "unreachable" << endl;
		else
			cout << na[sec] << endl;
	}
}
