#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

long long unsigned int fact(long long unsigned int min,long long unsigned int big)
{
	long long unsigned int sum = 1;
	for (long long unsigned int i = 0; i < min; i++)
	{
		sum *= (big-i);
		sum /= (1 + i);
	}
	return sum;
}

int main()
{
	long long unsigned int a, b;
	while (cin >> a >> b)
	{
		if (a==0 && b==0)
		{
			break;
		}
		else if ( b>a/2)
		{
			b = a - b;
		}
		cout << fact(b, a) << endl;
	}
}
