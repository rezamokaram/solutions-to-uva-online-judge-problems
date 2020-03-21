//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
const ll MAX = 9999999999;
//
int main()
{
	ll a, b, c;
	while (cin >> a >> b >> c)
	{
		ll d = min(a, b);
		b = max(a, b);
		//
		if (c%d == 0)
		{
			cout << c / d << endl;
		}
		else
		{
			ll p = c;
			int ans = 0;
			map<ll, pair<ll, ll>>g;
			int i = 0,min=c%d;
			g[c%d] = pair<ll, ll>(1, 0);
			while (c >= b)
			{
				c -= b;
				i++;
				g[c%d].first++;
				if (g[c%d].first>1)
				{
					break;
				}
				g[c%d].second = i;
				if (c%d<min)
				{
					min = c % d;
				}
			}
			cout << (p-(g[min].second*b)) / d + g[min].second;
			if (min) cout << " " << min;
			cout << endl;
			/*if (c%d == 0)
			{
				cout << c / d + ans << endl;
			}
			else
			{
				if (p%d<=p%b && p%d<=c%d)
				{
					cout << p / d << " " << p % d << endl;
				}
				else if (p%b<=p%d && p%b<=c%d)
				{
					cout << p / b << " " << p % b << endl;
				}
				else
				{
					cout << c / d + ans << " " << c % d << endl;
				}
			}*/
		}
	}
}
