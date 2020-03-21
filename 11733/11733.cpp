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
typedef pair<llu, pair<int, int>> nod;
nod ndc(int a, int b, llu val)
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
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		int m, n; llu ac;
		cin >> n >> m >> ac;
		pr.clear();
		for (size_t i = 0; i < n; i++)
			pr.push_back(i);
		vector<nod>p(m);
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			llu val;
			cin >> a >> b >> val;
			p[i] = ndc(a - 1, b - 1, val);
		}
		sort(p.begin(), p.end(), ui);
		llu ans = 0, zar = 0;
		int kk = n;
		for (size_t i = 0; i < m; i++)
		{
			int x = getp(p[i].second.second), y = getp(p[i].second.first);
			if (x != y)
			{
				kk--;
				pr[x] = y;
				if (p[i].first >= ac)zar++, ans += ac;
				else ans += p[i].first;
				if (kk == 1)break;
			}
		}

		cout << "Case #" << ++cs << ": " << kk * ac + ans << " " << zar + kk << endl;
	}
}
