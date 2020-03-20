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
int ds(ll n)
{
	int res=0;
	while (n)
	{
		res++;
		n /= 10;
	}
	return res * 9;
}
int dd(ll n)
{
	int res=0;
	while (n)
	{
		res+=n%10;
		n /= 10;
	}
	return res;
}
int main()
{
	int tc;
	cin >> tc; 
	while (tc--)
	{
		ll num;
		cin >> num;
		llu ans=0;
		for (ll i = num-ds(num)-1; i<=num; i++)
		{
			if (i+dd(i)==num)
			{
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}
