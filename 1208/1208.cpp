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
typedef pair<double, pair<int, int>> nod;
nod ndc(int a, int b, double val)
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
int getp(int n) { return pr[n] == n ? n : pr[n]=getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
double cmpt(no a, no b)
{
	double x = a.first > b.first ? a.first - b.first : b.first - a.first, y = a.second > b.second ? a.second - b.second : b.second - a.second;
	double res = (x * x) + (y * y);
	res = sqrt(res);
	return res;
}
int main()
{
	int tc,cs=0;
	cin >> tc;
	while (tc--)
	{
		ll n;
		cin >> n;
		pr.clear();
		priority_queue<nod,vector<nod>,greater<nod>>p;
		for (int i = 0; i < n; i++)
		{
			pr.push_back(i);
			for (int j = 0; j < n; j++)
			{
				llu val;
				char sine;
				cin >> val;
				if (j < n - 1)cin >> sine;
				if (i < j && val)p.push(ndc(i, j, val));
			}
		}
		cout << "Case " << ++cs << ":" << endl;
		for (size_t i = 0; p.size() ; i++)
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.second), y = getp(temp.second.first);
			if (x != y)
			{
				pr[x] = y;
				cout << char('A' + temp.second.first) << "-" << char('A' + temp.second.second) << " " << temp.first << endl;
			}
		}
	}
}
