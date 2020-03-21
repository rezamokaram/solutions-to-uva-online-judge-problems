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
		ll n, m;
		cin >> n >> m;
		pr.clear();
		priority_queue<nod,vector<nod>,greater<nod>>p;
		vector<no>li(n);
		for (int i = 0; i < n; i++)
		{
			pr.push_back(i);
			ll a, b;
			cin >> a >> b;
			li[i].first = a + 10000;
			li[i].second = b + 10000;
			for (int j = 0; j < i; j++)
				p.push(ndc(i, j, cmpt(li[i], li[j])));
		}
		double ans = 0, mnm = 0;int kk = n;
		for (size_t i = 0; p.size() ; i++)
		{
			nod temp = p.top();
			p.pop();
			int x = getp(temp.second.second), y = getp(temp.second.first);
			if (x != y)
			{
				pr[x] = y;
				if (temp.first <= m)ans += temp.first,kk--;
				else mnm += temp.first;
			}
		}
		cout << "Case #" << ++cs << ": ";
		printf("%d %.lf %.lf\n", kk, ans, mnm);
		//cout << "Case #" << ++cs << ": " << (ll)kk << " " << (ll)ans << " " << (ll)mnm << endl;
	}
}
