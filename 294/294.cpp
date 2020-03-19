#include <iostream>
#include <cmath>
using namespace std;
long long unsigned int f(long long unsigned int number)
{
	long long unsigned int n=sqrt(number),counter=0;
	for (long long unsigned int i = 1; i <= n; i++)
	{
		if (number%i==0)
		{
			counter++;
			if (number/i != i)
			{
				counter++;
			}
		}
	}
	return counter;
}
int main()
{
	long long unsigned int a,b,maxname=0, z, temp, max = 0;
	unsigned int n;
	cin >> n;
	for (size_t j = 0; j < n; j++)
	{
		maxname = 0, max = 0;
		cin >> a >> b;
		if (a==1 && b==1)
		{
			cout << "Between " << a << " and " << b << ", " << 1 << " has a maximum of " << 1 << " divisors.\n";
			continue;
		}
		for (z = a; z <= b; z++)
		{	
			temp = f(z);
			if (temp > max)
			{
				maxname = z;
				max = temp;
			}
		}
		cout <<"Between "<<a<<" and "<<b<<", "<<maxname<<" has a maximum of "<<max<<" divisors.\n";
	}
	system("pause>A");
}

