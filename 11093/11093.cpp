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
const ll MAX = 100000;
//
const int zero = 1010;
int main()
{
	int n, cs = 0;
	cin >> n;
	while (n--)
	{
		//if (cs == 81)cout << "oops" << endl;
		ll k;
		cin >> k;
		vector<ll>p(k);
		for (size_t i = 0; i < k; i++)
			cin >> p[i];
		ll sum = 0;
		bool f = 1;
		for (size_t i = 0; i < k; i++)
		{
			ll temp;
			cin >> temp;
			p[i] = p[i] - temp;
			sum += p[i];
		}
		ll maxi = 0, inds = 0;
		if (sum>=0)
		{
			bool ff = 0;
			for (size_t i = 0; i < k; i++)
			{
				if (p[i]>=0)
				{
					int ans = p[i], st = i;
					i++; 
					if (i >= k)ff = 1;
					i %= k;
					while (i != st && ans + p[i] >= 0)
					{
						ans += p[i++];
						if (i >= k)ff = 1;
						i %= k;
					}
					if (i==st)
					{
						inds = st;
					}
					if (ff)break;
				}
			}
		}
		cout << "Case " << ++cs << ": ";
		if (sum < 0)
			cout << "Not possible" << endl;
		else
			cout << "Possible from station "<< ++inds << endl;
	}
}
