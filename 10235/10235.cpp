#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool pcheck(long long unsigned int number)
{
	bool flag = true;
	for (size_t i = 2; i <= sqrt(number); i++)
	{
		if (number%i==0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

long long unsigned int rev(long long unsigned int number)
{
	long long unsigned int n = number,d=0;
	int len = 0;
	while (n>0)
	{
		n /= 10;
		len++;
	}
	len--;
	while (len>=0)
	{
		d += (number % 10)*pow(10, len);
		len--;
		number /= 10;
	}
	return d;
}

int main()
{
	long long unsigned int a;
	while (cin >> a)
	{
		if (pcheck(a) == false)
		{
			cout << a << " is not prime." << endl;
		}
		else
		{
			int r = rev(a);
			if (r != a && pcheck(r) == true)
			{
				cout << a << " is emirp." << endl;
			}
			else
			{
				cout << a << " is prime." << endl;
			}
		}
	}
}
