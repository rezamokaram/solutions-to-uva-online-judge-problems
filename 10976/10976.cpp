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
const int zero = 1010;
bool ui(no a, no b) { return (b.first < a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
void out(ll n, no a)
{
	cout << "1/" << n << " = 1/" << a.first << " + 1/" << a.second << endl;
}
int main()
{
	ll n;
	while (cin >> n)
	{
		vector<no>li;
		li.push_back(nc(n * 2, n * 2));
		ll base=n*2;
		for (int i = n*2-1; i > n; i--)
		{
			ll ne = i;
			ll big = lcm(ne, base);
			if (big % (2 * (big / base) - (big / ne))==0)
			{
				big /= (2 * (big / base) - (big / ne));
				li.push_back(nc(big, ne));
			}
			
		}
		sort(li.begin(), li.end(), ui);
		cout << li.size() << endl;
		for (size_t i = 0; i < li.size(); i++)
			out(n, li[i]);
	}
}
