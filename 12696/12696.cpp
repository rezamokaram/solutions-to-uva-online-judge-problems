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
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
int main()
{
	ll tc, ans = 0;
	cin >> tc;
	while (tc--)
	{
		double a[3], v;
		cin >> a[0] >> a[1] >> a[2] >> v;
		if (v <= 7.00)
		{
			if (double(a[0] + a[2] + a[1]) <= 125.00)
			{
				cout << 1 << endl;
				++ans;
			}
			else if (a[0] <= 56.00 && a[1] <= 45.00 && a[2] <= 25.00)
			{
				cout << 1 << endl;
				++ans;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else
		{
			cout << 0 << endl;
		}
	}
	cout << ans << endl;
}
