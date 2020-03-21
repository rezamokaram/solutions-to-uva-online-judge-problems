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
bool isprime(int x)
{
	if (x==1 || x==0)
	{
		return 0;
	}
	for (size_t i = 2; i <= sqrt(x); i++)
	{
		if (x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
//
llu gcd(llu a, llu b) { return(b == 0) ? a : gcd(b, a%b); }
llu lcm(llu a, llu b) { return ((a * b) / gcd(a, b)); };
int main()
{
	ll n;
	while (cin >> n && n)
	{
		vector<llu>list;
		for (size_t i = 1; i <= sqrt(n); i++)
		{
			if (n%i==0)
			{
				list.push_back(i);
				if (i!=n/i)
				{
					list.push_back(n / i);
				}
			}
		}
		llu ans = 0;
		for (size_t i = 0; i < list.size(); i++)
		{
			for (size_t j = i; j < list.size(); j++)
			{
				if (lcm(list[i],list[j])==n)
				{
					ans++;
				}
			}
		}
		cout << n << " " << ans << endl;
	}
}
