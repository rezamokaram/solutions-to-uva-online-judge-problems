#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		char k;
		cin >> k;
		int m, n;
		cin >> m >> n;
		if (k=='r' || k=='Q')
		{
			if (m>n)
			{
				cout << n << endl;
			}
			else
			{
				cout << m << endl;
			}
		}
		else if(k=='k')
		{
			int temp = m * n;
			if (temp%2==1)
			{
				cout << (temp / 2) + 1 << endl;
			}
			else
			{
				cout << (temp / 2) << endl;
			}
		}
		else if (k=='K')
		{
			int r , c;
			if (m%2==0)
			{
				r = (m / 2);
			}
			else
			{
				r = (m / 2) + 1;
			}
			if (n % 2 == 0)
			{
				c = (n / 2);
			}
			else
			{
				c = (n / 2) + 1;
			}
			cout << r * c << endl;
		}
	}
}
