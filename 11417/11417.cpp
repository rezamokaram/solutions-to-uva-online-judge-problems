#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
	int d=a;
	for (size_t i = 2; d > 0; i++)
	{
		if (a % d == 0 && b % d == 0)
		{
			return d;
		}
		d = a/i;
	}
	return 1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		int G = 0;
		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = i + 1; j <= n; j++)
			{
				G += GCD(i, j);
			}
		}
		cout << G << endl;
	}
}
