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
vector<vector<int>>li;
vector<int>vis,col;
int one, zero;
void bfs(int s)
{
	vis[s] = 1;
	if (col[s])one++;
	else zero++;
	for (size_t i = 0; i < li[s].size(); i++)
		if (!vis[li[s][i]])col[li[s][i]]=1-col[s],bfs(li[s][i]);
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		col.clear();
		vis.clear();
		li.clear();
		one = zero = 0;
		int a, e;
		cin >> a >> e;
		vector<int>p(e),pp(e),def;
		for (size_t i = 0; i < a; i++)
		{
			li.push_back(def);
			vis.push_back(0);
			col.push_back(0);
		}
		for (size_t i = 0; i < e; i++)
		{
			cin >> p[i] >> pp[i];
			li[p[i]].push_back(pp[i]);
			li[pp[i]].push_back(p[i]);
		}
		bool f = 0;
		int ans = 0;
		for (int i = 0; i < a; i++)
		{
			if (!vis[i])
			{
				one = zero = 0;
				bfs(i);
				ans += min(one, zero);
				if (!one || !zero)ans++;
			}
		}
		for (size_t i = 0; i < e; i++)
		{
			if (col[p[i]]==col[pp[i]])
			{
				f = 1;
				break;
			}
		}
		cout << (f ? -1 : ans) << endl;
	}
}
