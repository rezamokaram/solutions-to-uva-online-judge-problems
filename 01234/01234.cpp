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
typedef vector<pair<ll,ll>> vii;
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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n,m;
		cin >> n >> m;
		vector<ll>c(n + 1, 0);
		priority_queue<nod>p;
		prset(n + 2);
		ll mx = 0,ind=0;
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			llu val;
			cin >> a >> b >> val;
			c[a] += val;
			c[b] += val;
			p.push(ndc(a, b, val));
		}
		ll ssumm=0;
		while(p.size())
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.first), y = getp(temp.second.second);
			if (x != y)
			{
				pr[x] = y;
			}
			else
			{
				ssumm += temp.first;
			}
		}
		cout << ssumm << endl;
	}
	cin >> tc;
}
