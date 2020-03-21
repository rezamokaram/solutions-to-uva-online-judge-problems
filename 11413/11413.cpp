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
#define all(x) x.begin(),x.end()
//
using namespace std;
//
typedef int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 9999999999 + 1;
typedef pair<ll, pair<int, int>> edg;
//
int n, m;
vector<ll> li(10002);
bool ok(ll num)
{
	ll sum = 0, uc = 1;
	for (size_t i = 0; i < n; i++)
	{
		if (num < sum + li[i])
		{
			++uc;
			if (uc > m)
				return 0;
			sum = 0;
		}
		sum += li[i];
	}
	return 1;
}
int main()
{
	while (cin >> n >> m)
	{
		ll high = 0, low = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> li[i];
			high += li[i];
			low = max(low, li[i]);
		}
		if (n <= m)
			cout << low << endl;
		else
		{
			ll saved = high;
			while (low < high)
			{
				bool f = ok((low + high) >> 1);
				if (f)
				{
					high = (low + high) >> 1;
					saved = high;
				}
				else
					low = ((low + high) >> 1)+1;
			}
			cout << saved << endl;
		}
	}
}
