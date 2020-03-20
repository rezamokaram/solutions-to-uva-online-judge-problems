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
struct edge
{
	ll v, des;
	edge(ll vv, ll dd)
	{
		v = vv, des = dd;
	}
	bool operator >(const edge & sec) const
	{
		return(v > sec.v);
	}
};
//
int main()
{
	ll n, cs = 0;;
	while (cin >> n && n)
	{
		vector<int>li(n, 0);
		for (size_t i = 0; i < n; i++)
			cin >> li[i];
		bool f = 1;
		cout << "Game " << ++cs << ":\n";
		while (f)
		{
			bool ff = 1;
			int ex = 0, ok = 0;
			vector<int>no(11), nu(11);
			for (size_t i = 0; i < 11; i++)
				no[i] = nu[i] = 0;
			for (size_t i = 0; i < n; i++)
			{
				int dg;
				cin >> dg;
				if (dg)ff = 0;
				if (dg == li[i])ex++;
				else
				{
					if (no[dg])
					{
						ok++;
						no[dg]--;
					}
					else
					{
						nu[dg]++;
					}
					if (nu[li[i]])
					{
						ok++;
						nu[li[i]]--;
					}
					else
					{
						no[li[i]]++;
					}
				}
			}
			if (ff)f = 0;
			if (f)cout << "    (" << ex << "," << ok << ")\n";
		}
	}
}
