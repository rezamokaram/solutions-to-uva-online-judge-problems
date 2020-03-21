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
		if (a>b)
		{
			ll temp = a;
			a = b;
			b = temp;
		}
		int counter = 0;
		int sum = 0;
		while (b>0)
		{
			sum += ((b % 10) + (a % 10));
			b /= 10;
			a /= 10;
			sum /= 10;
			if (sum>0)
			{
				counter++;
			}
		}
		if (counter==0)
		{
			cout << "No carry operation." << endl;
		}
		else if (counter==1)
		{
			cout << "1 carry operation." << endl;
		}
		else
		{
			cout << counter << " carry operations." << endl;
		}
	}
}
