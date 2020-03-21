#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		long long int arr[10002];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int peak = 0;
		for (size_t i = 1; i < n-1; i++)
		{
			if (arr[i-1]-arr[i] > 0 && arr[i]-arr[i+1]<0)
			{
				peak += 1;
			}
			else if(arr[i - 1] - arr[i] < 0 && arr[i] - arr[i + 1] > 0)
			{
				peak += 1;
			}
		}
		if (arr[n - 1] - arr[0] > 0 && arr[0] - arr[1] < 0)
		{
			peak += 1;
		}
		else if (arr[n - 1] - arr[0] < 0 && arr[0] - arr[1] > 0)
		{
			peak += 1;
		}
		if (arr[n - 2] - arr[n-1] > 0 && arr[n-1] - arr[0] < 0)
		{
			peak += 1;
		}
		else if (arr[n - 2] - arr[n-1] < 0 && arr[n-1] - arr[0] > 0)
		{
			peak += 1;
		}
		cout << peak << endl;
	}
}
