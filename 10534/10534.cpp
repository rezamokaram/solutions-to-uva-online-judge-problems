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
	int n;
	while (cin >> n)
	{
		vector<int>a(n), b(n), la(n), lb(n),aa,bb;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[n - i - 1] = a[i];
			la[i] = lb[i] = 1;
		}
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			int posa = lower_bound(aa.begin(), aa.end(), a[i]) - aa.begin();
			if (posa == aa.size())
				aa.push_back(a[i]);
			else
				aa[posa] = min(aa[posa], a[i]);
			int posb = lower_bound(bb.begin(), bb.end(), b[i]) - bb.begin();
			if (posb == bb.size())
				bb.push_back(b[i]);
			else
				bb[posb] = min(bb[posb], b[i]);
			la[i] = posa+1;
			lb[i] = posb+1;
		}
		for (int i = 0; i < n; i++)
		{
			mx = max(mx, min(la[i], lb[n - i - 1]));
		}
		cout << 2*mx-1 << endl;
	}
}
