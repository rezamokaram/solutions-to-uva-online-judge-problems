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
typedef vector<pair<int,ll>> vi;
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
int getp(int n) { return pr[n] == n ? n : pr[n]=getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
int main()
{
	ll n, m,cs=0;
	while (cin >> n >> m && n)
	{
		pr.clear();
		for (size_t i = 0; i < n; i++)
			pr.push_back(i);
		int index = 0;
		map<string, int>g;
		priority_queue<nod>qu;// , vector<nod>, greater<nod >> qu;
		ll ans = 999999999;
		for (size_t i = 0; i < m; i++)
		{
			string a, b;
			ll val;
			cin >> a >> b >> val;
			if (!g[a])g[a] = ++index;
			if (!g[b])g[b] = ++index;
			int aa = g[a] - 1, bb = g[b] - 1;
			qu.push(ndc(aa, bb, val));
			
		}
		string ss, ee;
		cin >> ss >> ee;
		int s = g[ss] - 1, e = g[ee] - 1;
		int kk = 0;
		while (qu.size())
		{
			nod temp = qu.top();
			qu.pop();
			int x = getp(temp.second.first), y = getp(temp.second.second);
			if (x!=y)
			{
				++kk;
				pr[x] = y;
				ans = min(ans, temp.first);
			}
			if (getp(s) == getp(e))break;
			//if (kk == n - 1)break;
		}

		cout << "Scenario #" << ++cs << endl;
		cout << ans << " tons\n" << endl;
	}
}
