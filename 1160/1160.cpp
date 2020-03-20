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
typedef vector<pair<int,int>> vii;
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
void prset(ll a)
{
	pr.clear();
	for (int i = 0; i < a; i++)
	{
		pr.push_back(i);
	}
}
int getp(int n) { return pr[n] == n ? n : pr[n]=getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
int main()
{
	while (1)
	{
		bool br = 0;
		int a, b,mx=0;
		vii c;
		while (cin >> a && a!=-1)
		{
			cin >> b;
			c.push_back(pair<int,int>(a, b));
			br = 1;
			mx = max(mx, max(a, b));
		}
		if (!br)break;
		prset(mx+1);
		int ans = 0;
		for (size_t i = 0; i < c.size(); i++)
		{
			int x = getp(c[i].first), y = getp(c[i].second);
			if (x != y)
			{
				pr[x] = y;
			}
			else
				ans++;
		}
		cout << ans << endl;
	}
}
