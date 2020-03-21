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

//
int main()
{
	ll n;
	while (cin >> n)
	{
		if (n<0)
		{
			break;
		}
		if (n==0)
		{
			cout << 1 << endl;
			continue;
		}
		if (n==1)
		{
			cout << 2 << endl;
			continue;
		}
		ll a1 = 1, a2 = 2,a3;
		for (size_t i = 1; i < n; i++)
		{

			ll temp = a2;
			a3 = (a2 - a1) + a2 + 1;
			a1 = temp;
			a2 = a3;
		}
		cout << a2 << endl;
	}
}
