#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
ll magic(ll a, ll b, ll c, ll x)
{
	ll main = (a*(x*x)) + (b*x) + c;
	return main;
}
//
int main()
{
	ll a, b, c, d, l;
	while (cin >> a >> b >> c >> d >> l)
	{
		if (a==0 && b==0 && c==0 && d==0 && l==0)
		{
			break;
		}
		ll counter = 0;
		for (ll i = 0; i <= l; i++)
		{
			ll ans = magic(a, b, c, i);
			if (ans%d==0)
			{
				counter++;
			}
		}
		cout << counter << endl;
	}
}
