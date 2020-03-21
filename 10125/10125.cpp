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
vector<int>list, pp, par, inn;
void printt(int d)
{
	
	if(pp[d]!=d)printt(pp[d]);
	cout << par[d] << endl;
}
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<ll>li(n);
		ll ans = 9999999999;
		for (size_t i = 0; i < n; i++)
		{
			cin >> li[i];
			ans = min(ans, li[i]);
		}
		sort(li.begin(), li.end());

		bool f = 0;
		//
		for (int i = n-1; i >= 2; i--)
		{
			for (int j = i-1; j >= 1; j--)
			{
				for (int z = j-1; z >= 0; z--)
				{
					int pos = lower_bound(li.begin(), li.end(), li[i] + li[j] + li[z]) - li.begin();
					if (pos<n && pos != i && pos != j && pos != z && li[pos]==li[i]+li[j]+li[z])
					{
						ans = max(ans, li[i] + li[j] + li[z]);
						f = 1;
					}
				}
			}
		}
		//
		if (f)
			cout << ans << endl;
		else
			cout << "no solution" << endl;
	}
}
