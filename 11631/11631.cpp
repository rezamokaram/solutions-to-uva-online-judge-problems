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
typedef pair<ll, pair<int, int>> nod;
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
typedef pair<ll, ll> no;
no nc(ll a, ll b) { return pair<ll, ll>(a, b); }
//
bool ui(no a, no b) { return (b.first < a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
int main()
{
	int m, n;
	while (cin >> m >> n && m && n)
	{
		pr.clear();
		priority_queue<nod, vector<nod>, greater<nod>>p;
		for (size_t i = 0; i < m; i++)
		{
			pr.push_back(i);
		}
		ll sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			int s, e;
			ll w;
			cin >> s >> e >> w;
			sum += w;
			p.push(ndc(s, e, w));
		}
		ll ans = 0;
		//vector<nod>dbg;
		while (p.size())
		{
			nod temp = p.top();
			p.pop();
			//dbg.push_back(temp);
			if (getp(temp.second.first) != getp(temp.second.second))
			{
				pr[getp(temp.second.second)] = getp(temp.second.first);
				ans += temp.first;
			}
		}
		cout << sum - ans << endl;
	}
}
