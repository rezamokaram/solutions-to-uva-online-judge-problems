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
ll cmpt(string a,string b)
{
	ll ans = 0,ans2=0;
	for (size_t i = 0; i < 4; i++)
	{
		int aa = a[i]-'0';
		int bb = b[i]-'0';
		if (aa == bb)continue;
		ans += min(llabs(aa - bb), (ll)(10 - max(aa,bb)) + min(aa,bb));
		ans2 += llabs(aa-bb);
	}
	//return min(ans, ans2);
	//return ans;
	return ans;
}
int stw(string d)
{
	int res = 0;
	for (size_t i = 0; i < 4; i++)
	{
		res += d[i] - '0';
	}
	return res;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		pr.clear();
		int n;
		cin >> n;
		for (size_t i = 0; i < n+1; i++)
		{
			pr.push_back(i);
		}
		vector<nod>p;
		vector<string>li(n + 1);
		li[0] = "0000";
		ll mnm = 9999;
		for (size_t i = 1; i < n+1; i++)
		{
			cin >> li[i];
			mnm = min(mnm, cmpt("0000",li[i]));
			for (size_t j = 1; j < i; j++)
			{
				p.push_back(ndc(i, j,cmpt(li[i], li[j])));
			}
		}
		sort(p.begin(), p.end(), ui);
		ll ans = 0;
		vector<int>vis(n, 0);
		for (size_t i = 0; i < p.size(); i++)
		{
			int x = getp(p[i].second.first), y = getp(p[i].second.second);
			if (x!=y)
			{
				ans += p[i].first;
				pr[x] = y;
			}
		}
		cout << ans + mnm << endl;
	}
}
