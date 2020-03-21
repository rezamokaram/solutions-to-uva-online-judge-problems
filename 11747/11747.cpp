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
int main()
{
	int m, n;
	while (cin >> m >> n && m)
	{
		pr.clear();
		for (size_t i = 0; i < m; i++)
			pr.push_back(i);
		vector<nod>li(n);
		for (size_t i = 0; i < n; i++)
		{
			int a, b;
			ll val;
			cin >> a >> b >> val;
			li[i] = ndc(a, b, val);
		}
		sort(li.begin(), li.end(), ui);
		vector<ll>ans;
		for (size_t i = 0; i < n; i++)
		{
			int f = li[i].second.first, s = li[i].second.second;
			if (getp(f) != getp(s))
				pr[getp(f)] = pr[getp(s)];
			else
				ans.push_back(li[i].first);
		}
		if (!ans.size())cout << "forest";
		else 
			for (size_t i = 0; i < ans.size(); i++)
			{
				if (i)cout << " ";
				cout << ans[i];
			}
		cout << endl;
	}
}
