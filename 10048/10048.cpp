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
	li.clear();
	pr.clear();
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
int main()
{
	int n, m, d, cs = 0;
	while (cin >> n >> m >> d && n)
	{
		if (cs)cout << endl;
		cout << "Case #" << ++cs << endl;
		priority_queue<nod, vector<nod>, greater<nod>>p;
		prset(n + 2);
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			llu val;
			cin >> a >> b >> val;
			p.push(ndc(a, b, val));
		}
		int pc = 0;
		while (p.size())
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.first), y = getp(temp.second.second);
			if (x != y)
			{
				pr[x] = y;
				pc++;
				li[temp.second.second].push_back(pii(temp.second.first, temp.first));
				li[temp.second.first].push_back(pii(temp.second.second, temp.first));
			}
			if (pc == n - 1)break;
		}
		vector<vi>ans(1);
		for (size_t i = 1; i < n ; i++)
		{
				vi z(n + 1, 0);
				vector<bool>vis(n + 1, 0);
				queue<int>sd;
				sd.push(i);
				while (sd.size())
				{
					int nob = sd.front();
					sd.pop();
					if (vis[nob])continue;
					vis[nob] = 1;
					for (size_t j = 0; j < li[nob].size(); j++)
					{
						int sec = li[nob][j].second, fer = li[nob][j].first;
						if (sec && !vis[fer])
						{
							if (!vis[fer])sd.push(fer);
							z[fer] = max(z[nob], sec);
						}
					}
					//if (vis[b])break;
				}
				ans.push_back(z);
		}
		for (size_t i = 0; i < d; i++)
		{
			int a, b;
			cin >> a >> b;
			if (getp(a) == getp(b))
				cout << ans[min(a, b)][max(a, b)] << endl;
			else
				cout << "no path" << endl;
		}
	}
}
