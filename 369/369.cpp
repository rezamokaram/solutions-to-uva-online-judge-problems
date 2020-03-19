#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	ll a, b;
	while (cin >> a >> b)
	{
		if (a==0 && b==0)
		{
			break;
		}
		bool f = true;
		if (b>a)
		{
			ll temp = a;
			a = b;
			b = temp;
			f = false;
		}
		ll sum = 1;
		ll temp2 = b;
		if (b>(a/2))
		{
			temp2 = a - b;
		}
		for (size_t i = 0; i < temp2; i++)
		{
			sum *= (a - i);
			sum /= (i + 1);
		}
		if (f==true)
		{
			cout << a << " things taken " << b << " at a time is " << sum << " exactly." << endl;
		}
		else
		{
			cout << b << " things taken " << a << " at a time is " << sum << " exactly." << endl;
		}
	}
}
