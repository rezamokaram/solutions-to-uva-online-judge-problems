#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;



int main()
{
	long long int a;
	while (cin >> a)
	{
		long long int temp = a;
		int len = 0;
		if (a==0)
		{
			break;
		}
		int arr[200];
		if (a<0)
		{
			a *= -1;
			arr[len] = -1;
			len++;
		}
		long long int n = sqrt(a);
		for (long long int i=2; i <= n ; i++)
		{
			if (a%i==0)
			{
				while (a%i==0)
				{
					a /= i;
					arr[len] = i;
					len++;
				}
			}
			if (a<=1)
			{
				break;
			}
		}
		if (a>1)
		{
			arr[len] = a;
			len++;
		}
		cout << temp << " = ";
		for (size_t j = 0; j < len; j++)
		{
			if (j==0)
			{
				cout << arr[j];
			}
			else
			{
				cout << " x " << arr[j];
			}
		}
		cout << endl;
	}
}
