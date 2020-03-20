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
void bfs(vector<vector<int>>&p, vector<bool>&vis, int start)
{
	for (size_t i = 0; i < p[start].size(); i++)
		if (!vis[p[start][i]])
			vis[p[start][i]]=1,bfs(p, vis, p[start][i]);
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<vector<int >> p(n);
		int s;
		while (cin >> s && s)
		{
			s--;
			int k;
			while (cin >> k && k)
			{
				k--;
				p[s].push_back(k);
			}
		}
		int d;
		cin >> d;
		
		for (size_t i = 0; i < d; i++)
		{
			vector<bool>vis(n, 0);
			int start;
			cin >> start;
			bfs(p, vis, start-1);
			vector<int>ans;
			for (size_t i = 0; i < n; i++)
			{
				if (!vis[i])ans.push_back(i + 1);
			}
			cout << ans.size();
			for (size_t i = 0; i < ans.size(); i++)
			{
				cout << " " << ans[i];
			}
			cout << endl;
		}
		
	}
}
