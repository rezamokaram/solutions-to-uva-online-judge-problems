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
const int mmx = 100001;
ll arr[mmx];
void sst()
{
	arr[0] = 1;
	arr[1] = 2;
	for (ll i = 2; i < mmx; i++)
	{
		ll res = arr[i - 1];
		const ll pp = res;
		ll sq = sqrt(arr[i - 1]);
		if (sq*sq == pp)res++;
		else if (pp%sq == 0)
			res += 2;
		for (ll j = 1; j < sq; j++)
			if (pp % j == 0)
				res += 2;// (j == sq ? 1 : 2);
		arr[i] = res;
	}
}
//
int main()
{
	sst();
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		ll a, b;
		cin >> a >> b;
		ll ans1 = (lower_bound(arr, arr + mmx, max(a, b)) - arr);
		if (arr[ans1] == max(a, b))
			ans1++;
		ll ans2 = (lower_bound(arr, arr + mmx, min(a, b)) - arr);
		ll ans = ans1 - ans2;
		cout << "Case " << ++cs << ": " << ans << endl;
	}
}
