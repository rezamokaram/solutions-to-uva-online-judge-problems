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
int getp(int n) { return pr[n] == n ? n : pr[n]=getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
int main()
{
	int n, m;
	while (cin >> n >> m && n)
	{
		pr.clear();
		priority_queue<nod,vector<nod>,greater<nod>>p;
		map<string, int>g;
		for (int i = 0; i < n; i++)
		{
			pr.push_back(i);
			string name;
			cin >> name;
			g[name] = i;
		}
		for (size_t i = 0; i < m; i++)
		{
			string a, b;
			llu val;
			cin >> a >> b >> val;
			p.push(ndc(g[a], g[b], val));
		}
		string wtf; cin >> wtf;
		llu ans = 0, mnm = 0;
		for (size_t i = 0; p.size() ; i++)
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.second), y = getp(temp.second.first);
			if (x != y)
			{
				pr[x] = y;
				ans++;
				mnm += temp.first;
				
			}
			if (ans == n - 1)break;
		}
		if (ans == n - 1)cout << mnm << endl;
		else cout << "Impossible" << endl;
	}
}
