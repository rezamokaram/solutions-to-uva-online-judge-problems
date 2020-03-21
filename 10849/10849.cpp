#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
bool is_black(llu n, ll x, ll y)
{
	if (((x*n) + y) % 2 == x%2)
	{
		return 0;
	}
	return 1;
}
bool inv(llu n, ll x, ll y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}
int main()
{
	ll tc;
	cin >> tc;
	while (tc--)
	{
		llu k, n;
		cin >> k >> n;
		for (ll i = 0; i < k; i++)
		{
			ll a, b, x, y;
			cin >> a >> b >> x >> y;
			if (a == x && y == b)
			{
				cout << 0 << endl;
			}
			else if ((a+b)%2== (x+ y)%2 && inv(n, a, b) && inv(n, x, y))
			{
				if (abs(a - x) == abs(y - b))
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 2 << endl;
				}
			}
			else
			{
				cout << "no move" << endl;
			}
		}
	}
}
