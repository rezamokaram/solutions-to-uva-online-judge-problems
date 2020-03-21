#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

long long int f(long long int number,long long int x)
{
	if (x==1 || x==0)
	{
		return 1;
	}
	if (number%x == 0)
	{
		while (number%x == 0)
		{
			number /= x;
			if (number < 1)
			{
				break;
			}
			if (number == 1)
			{
				return 0;
			}

		}
	}
	return 1;
}


int main()
{
	long long int a,b;
	while (cin >> a >> b)
	{
		if (b > a || b <= 1 )
		{
			cout << "Boring!" << endl;
		}
		else if (a % b != 0 || a <= 1)
		{
			cout << "Boring!" << endl;
		}
		else if (a == b)
		{
			cout << a << " " << 1 << endl;
		}
		else
		{
			if (f(a, b) == 1)
			{
				cout << "Boring!" << endl;
			}
			else
			{
				while (a > 0)
				{
					cout << a;
					if (a != 1)
					{
						cout << " ";
					}
					a /= b;
				}
				cout << endl;
			}
		}
	}
}
