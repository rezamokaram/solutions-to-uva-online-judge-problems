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
const int MAX = 10000;
//
int main()
{
	ll s, n;
	while (cin >> s >> n && s && n)
	{
		ll d = sqrt(n);
		ll sb = d;
		ll x = 0, y = 0;
		if (d%2==1)
		{
			x = d;
			y = d;
			ll ek = n - d * d;
			if (!ek)
			{
				sb = d;
				x = sb;
				y = sb;
			}
		    else if (ek<=d)
			{
				sb+=2;
				x = sb-(ek);
				y=sb;
			}
			else if (ek==d+1)
			{
				sb += 2;
				x = 1;
				y = sb;
			}
			else
			{
				sb += 2;
				x = 1;
				y = sb - (ek - (d + 1));
			}
		}
		else
		{
			sb++;
			x = 1;
			y = 1;
			ll ek = n - d * d;
			if (!ek)
			{
				x = 1;
				y = 2;
			}
			else if (ek <= d)
			{
				x += (ek-1);
				y = 1;
			}
			else if (ek == d + 1)
			{
				x = sb;
				y = 1;
			}
			else
			{
				x = sb;
				y += ek - (d + 1);
			}
		}
		ll an = (s - sb) / 2;
		x += an; y += an;
		cout << "Line = " << y << ", column = " << x << "." << endl;
	}
}
