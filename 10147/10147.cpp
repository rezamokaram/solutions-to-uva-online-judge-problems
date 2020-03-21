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
typedef vector<pair<ll, ll>> vii;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAX = 100000;
typedef pair<ll, pair<int, int>> nod;
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
typedef pair<llu, llu> no;
no nc(ll a, ll b) { return pair<ll, ll>(a, b); }
//
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
vector<vector<pii>>li;
void prset(ll a)
{
	pr.clear();
	li.clear();
	for (int i = 0; i < a; i++)
	{
		pr.push_back(i);
		vector<pii>z;
		li.push_back(z);
	}
}
int getp(int n) { return pr[n] == n ? n : pr[n] = getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
ll cmpt(pii a, pii b)
{
	ll x = abs(a.first - b.first), y = abs(a.second - b.second);
	x *= x;
	y *= y;
	x += y;
	return x;
}
int main()
{
	bool ff = 1;
	int tc;
	cin >> tc;
	while (tc--)
	{
		if (!ff)cout << endl;
		ff = 0;
		int n;
		cin >> n;
		priority_queue<nod, vector<nod>, greater<nod>>p;
		vector<pii>ns(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> ns[i].first >> ns[i].second;
			for (size_t j = 0; j < i; j++)
				p.push(ndc(i + 1, j + 1, cmpt(ns[i], ns[j])));
		}
		prset(n + 2);
		int m;
		cin >> m;
		int ans = 0;
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			int x = getp(a), y = getp(b);
			if (x != y)
			{
				pr[x] = y;
				ans++;
			}
		}
		if (ans < n - 1)
		{
			while (p.size())
			{
				nod temp = p.top();
				p.pop();
				int a = temp.second.first, b = temp.second.second;
				int x = getp(a), y = getp(b);
				if (x != y)
				{
					pr[x] = y;
					cout << b << " " << a << endl;
					ans++;
				}
				if (ans == n - 1)break;
			}

		}
		else
		{
			cout << "No new highways need" << endl;
		}
		
	}
}
