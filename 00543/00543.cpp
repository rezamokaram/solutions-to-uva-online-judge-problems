#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

bool prime(ll number)
{
	if (number<2)
	{
		return false;
	}
	for (size_t i = 2; i <= sqrt(number); i++)
	{
		if (number%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ll n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		if (n%2==0)
		{
			for (ll i = n-3; true ; i-=2)
			{
				if (prime(i) && prime(n-i))
				{
					cout << n << " = " << n - i << " + " << i << endl;
					break;
				}
			}
		}
		else
		{
			for (ll i = n - 2; true; i -= 2)
			{
				if (prime(i) && prime(n - i))
				{
					cout << n << " = " << n - i << " + " << i << endl;
					break;
				}
			}
		}
	}
}
