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
using namespace std;
//
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 9999999999 + 1;
typedef pair<ll, pair<int, int>> edg;
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll a, b, c, ans = 0;
		cin >> a >> b >> c;
		a += b;
		while (a>=c)
		{
			ll now = a / c;
			a %= c;
			a += now;
			ans += now;
		}
		cout << ans << endl;
	}
}
