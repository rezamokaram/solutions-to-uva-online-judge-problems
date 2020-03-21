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
typedef pair<ll, ll> no;
no nc(ll a, ll b) { return pair<ll, ll>(a, b); }
//
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
double cmpt(pair<double, double>a, pair<double, double>b)
{
	a.first = (a.first > b.first ? a.first - b.first : b.first - a.first);
	a.second= (a.second > b.second ? a.second - b.second : b.second - a.second);
	double res = a.first*a.first + a.second*a.second;
	res = sqrt(res);
	return res;
}
int main()
{
	int tc;
	cin >> tc;
	bool f = 0;
	while (tc--)
	{
		if (f)cout << endl;
		f = 1;
		pr.clear();
		int n;
		cin >> n;
		vector<pair<double, double>>li(n);
		vector<nod>p;
		for (size_t i = 0; i < n; i++)
		{
			pr.push_back(i);
			cin >> li[i].first >> li[i].second;
			for (size_t j = 0; j < i; j++)
				p.push_back(ndc(i, j, cmpt(li[i], li[j])));
		}
		sort(p.begin(), p.end(), ui);
		double ans = 0;
		for (size_t i = 0; i < p.size(); i++)
		{
			int x = getp(p[i].second.first), y = getp(p[i].second.second);
			if (x!=y)
				pr[y] = x,ans+=p[i].first;
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
}
