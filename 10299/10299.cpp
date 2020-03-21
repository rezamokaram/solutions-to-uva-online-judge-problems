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
int main()
{
	llu n;
	while (cin >> n && n)
	{
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		llu ans = n;
		for (llu i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
				ans -= ans / i;
			while (n%i==0)
				n /= i;
		}
		if (n != 1)
			ans -= ans / n;
		cout << ans << endl;
	}
}
