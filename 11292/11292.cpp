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
int main()
{
	ll n, m;
	while (cin >> n >> m && n && m)
	{
		ll t;
		priority_queue<ll, vector<ll>, greater<ll>>hd, kn;
		for (size_t i = 0; i < n; i++)
			cin >> t,hd.push(t);
		for (size_t i = 0; i < m; i++)
			cin >> t, kn.push(t);
		ll ans = 0;
		t = hd.top();
		while (hd.size() && kn.size())
		{
			ll u = kn.top();
			kn.pop();
			if (u >= t)
			{
				ans += u;
				if (hd.size())hd.pop();
				if (hd.size())t = hd.top();
			}
		}
		if (hd.size())
			cout << "Loowater is doomed!" << endl;
		else
			cout << ans << endl;
	}
}
