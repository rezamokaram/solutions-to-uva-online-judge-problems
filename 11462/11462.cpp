#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	
	long long int arr[2000000], n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (size_t i = 0; i < n; i++)
		{
			if (i==0)
			{
				cout << arr[i];
			}
			else
			{
				cout << " " << arr[i];
			}
		}
		cout << endl;
	}
}
