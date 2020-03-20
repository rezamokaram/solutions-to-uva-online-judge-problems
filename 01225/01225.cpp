#include <iostream>
#include <string>
#include <algorithm>
//#include <ctring>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int n;
		cin >> n;
		int arr[10] = { 0 };
		for (int j = 1; j <= n; j++)
		{
			int number = j;
			while (number > 0)
			{
				arr[number % 10]++;
				number /= 10;
			}
		}
		//
		for (size_t j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				cout << arr[j];
				continue;
			}
			cout << " " << arr[j];
		}
		cout << endl;
	}
}
