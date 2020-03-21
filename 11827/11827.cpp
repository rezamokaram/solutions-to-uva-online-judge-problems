#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int gcd(int min, int max)
{
	for (size_t i = 1; i <= min ; i++)
	{
		int a = min / i;
		if (min%a==0 && max%a==0)
		{
			return a;
		}
	}
	return 1;
}

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	for (size_t z = 0; z < tc; z++)
	{
		string a;
		getline(cin, a);
		int arr[100];
		int len = a.length();
		int counter = 0 ,size = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (a[i]==' ')
			{
				continue;
			}
			counter++;
			if (i == len - 1 || a[i+1] == ' ')
			{
				arr[size] = 0;
				for (size_t j = 0; j < counter ; j++)
				{
					int temp = a[i - j] - '0';
					arr[size] += temp * pow(10, j);
				}
				size++;
				counter = 0;
				i++;
			}
		}
		//
		sort(arr, arr + size);
		int max = 0;
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				int g = gcd(arr[i], arr[j]);
				if (max<g)
				{
					max = g;
				}
			}
		}
		cout << max << endl;
	}
}
