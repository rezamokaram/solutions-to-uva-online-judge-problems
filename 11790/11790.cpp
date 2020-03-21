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
//
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		ll n, mx = -1, mmx = -1;
		cin >> n;
		vector<ll>li(n), weight(n), lir(n, 0), lil(n, 0);
		for (size_t i = 0; i < n; i++)
			cin >> li[i];
		for (size_t i = 0; i < n; i++)
			cin >> weight[i], lir[i] = lil[i] = weight[i];
		//
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (li[i] > li[j])
				{
					if (lir[j] + weight[i] > lir[i])
					{
						lir[i] = lir[j] + weight[i];
					}
				}
				//
				if (li[n - i - 1] > li[n - j - 1])
				{
					if (lil[n - j - 1] + weight[n - i - 1] > lil[n - i - 1])
					{
						lil[n - i - 1] = lil[n - j - 1] + weight[n - i - 1];
					}
				}
			}
			mx = max(mx, lir[i]);
			mmx = max(mmx, lil[n - 1 - i]);
		}
		//
		cout << "Case " << ++cs << ". ";
		if (mx >= mmx)
		{
			cout << "Increasing (" << mx << "). Decreasing (" << mmx << ")." << endl;
		}
		else
		{
			cout << "Decreasing (" << mmx << "). Increasing (" << mx << ")." << endl;
		}
	}
}
