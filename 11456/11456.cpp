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
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		ll mx = 0;
		vector<ll>p(n);
		vector<ll>lis;
		deque<ll>iis;
		for (int i = 0; i < n; i++)
			cin >> p[n-i-1];
		for (int i = 0; i < n; i++)
		{
			int pqp = 1;
			ll posr = lower_bound(lis.begin(), lis.end(), p[i]) - lis.begin();
			ll posl = lower_bound(iis.begin(), iis.end(), p[i]) - iis.begin();
			if (posr == lis.size())
				lis.push_back(p[i]);
			else
				lis[posr] = min(lis[posr], p[i]);
			if (posl == 0)
				iis.push_front(p[i]), pqp = 0;
			else
				iis[posl - 1] = max(iis[posl - 1], p[i]);
			mx = max((ll)(posr + (iis.size()-posl+pqp)), mx);
		}
		cout << mx << endl;
	}
}
