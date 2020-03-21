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
int main()
{
	ll n;
	while (cin >> n && n)
	{
		ll sq = sqrt(n);
		int x, y;
		if (sq%2)
		{
			x = 1;
			y = sq;
			n -= sq * sq;
			if (n>=sq+1)
			{
				y++;
				n -= sq + 1;
				x = sq + 1;
			}
			else if(n)
			{
				y++;
				x = n;
				n = 0;
			}
			if (n)
			{
				y -= n;
				n = 0;
			}
		}
		else
		{
			y = 1;
			x = sq;
			n -= sq * sq;
			if (n>=sq+1)
			{
				x++;
				n -= sq + 1;
				y = sq + 1;
			}
			else if(n)
			{
				x++;
				y=n;
				n = 0;
			}
			if (n)
			{
				x -= n;
				n = 0;
			}
		}
		cout << x << " " << y << endl;
	}
}
