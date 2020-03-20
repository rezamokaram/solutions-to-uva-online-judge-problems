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
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
double cmpt(pair<double, double>a, pair<double, double>b)
{
	a.first = (a.first > b.first ? a.first - b.first : b.first - a.first);
	a.second= (a.second > b.second ? a.second - b.second : b.second - a.second);
	double res = a.first*a.first + a.second*a.second;
	res = sqrt(res);
	return res;
}
int main()
{
	int tc;
	cin >> tc;
	bool f = 0;
	while (tc--)
	{
		if (f)cout << endl;
		f = 1;
		pr.clear();
		map<string, int>g;
		int n, m, index = 1;
		cin >> n >> m;
		vector<nod>p(m);
		for (size_t i = 0; i < n; i++)
			pr.push_back(i);
		for (size_t i = 0; i < m; i++)
		{
			string a, b;
			ll c;
			cin >> a >> b >> c;
			if (!g[a])g[a] = index++;
			if (!g[b])g[b] = index++;
			p[i] = ndc(g[a] - 1, g[b] - 1, c);
		}
		sort(p.begin(), p.end(), ui);
		ll ans = 0;
		for (size_t i = 0; i < m; i++)
		{
			int x = getp(p[i].second.second), y = getp(p[i].second.first);
			if (x != y)
				pr[x] = y, ans += p[i].first;
		}
		cout << ans << endl;
	}
}
