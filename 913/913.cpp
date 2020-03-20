#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	ll a;
	while (cin >> a)
	{
		ll sum = 1;
		for (ll i = 3; i <= a; i+=2)
		{
			sum += i * 2;
		}
		cout << 3*(sum-2) << endl;
	}

}
