#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;
vector <string> list;

void fib()
{
	int number = 5001;
	list.push_back("0");
	list.push_back("1");
	int maxsize = 1;
	for (size_t i = 2; i <= number; i++)
	{
		char a[9000];
		int sum = 0;
		int j;
		for (j = 0; j < maxsize; j++)
		{
			if (j < list[i - 2].length())
			{
				int temp = list[i - 2][j] - '0';
				sum += temp;
			}
			if (j < list[i - 1].length())
			{
				int temp = list[i - 1][j] - '0';
				sum += temp;
			}
			a[j] = '0' + (sum % 10);
			sum /= 10;

		}
		if (sum > 0)
		{
			while (sum > 0)
			{
				a[j] = '0' + (sum % 10);
				sum /= 10;
				j++;
			}
		}
		a[j] = '\0';
		if (j > maxsize)
		{
			maxsize = j;
		}
		list.push_back(a);
	}
}


int main()
{
	fib();
	int number;
	while (cin >> number)
	{
		cout << "The Fibonacci number for " << number << " is ";
		for (int j = list[number].length() - 1; j >= 0; j--)
		{
			cout << list[number][j];
		}
		cout << endl;
	}
}
