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
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll n,mx;
		cin >> n;
		vector<ll>p(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> p[i];
			if (i == 1)mx = p[0] - p[1];
		}
		ll nmm = p[p.size() - 1];
		for (ll i = n-2; i >= 0; i--)
		{
			mx = max(mx, p[i] - nmm);
			nmm = min(nmm, p[i]);
		}
		cout << mx << endl;
	}
}
