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
int main()
{
	int n, cs = 0, perv;
	vector<int>d;
	while (cin >> n)
	{
		if (n == -1 && perv == -1)
			break;
		if (n >= 0)
			d.push_back(n), perv = n;
		else
		{
			perv = n;
			int g = 0;
			vector<int>b(d.size());
			for (int i = d.size() - 1; i >= 0; i--)
				b[g++] = d[i];
			int mx = LIS(b);
			if (cs)cout << endl;
			cout << "Test #" << ++cs << ":\n  maximum possible interceptions: " << mx << endl;
			d.clear();
		}
	}
}
