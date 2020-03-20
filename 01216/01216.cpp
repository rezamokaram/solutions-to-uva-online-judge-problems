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
typedef pair<llu, pair<int, int>> nod;
nod ndc(int a, int b, llu val)
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
		int n;
		cin >> n;
		int a, b;
		vii c;
		priority_queue<nod, vector<nod>, greater<nod>>p;
		int ans = 0;
		while (cin >> a && a!=-1)
		{
			cin >> b;
			for (size_t i = 0; i < c.size(); i++)
			{
				llu x = abs(a - c[i].first), y = abs(b - c[i].second);
				x *= x;
				y *= y;
				x += y;
				llu sq = sqrt(x);
				if (sq*sq != x)sq++;
				p.push(ndc(i, c.size(), sq));
			}
			c.push_back(pair<int, int>(a, b));
			ans++;
		}
		prset(c.size() + 1);
		for (size_t i = 0; p.size(); i++)
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.first), y = getp(temp.second.second);
			if (x != y)
			{
				pr[x] = y;
				ans--;
			}
			if (ans<=n)
			{
				cout << temp.first << endl;
				break;
			}
		}
	}
}
