#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;


int main()
{
	int tc;
	cin >> tc;
	for (size_t z = 0; z < tc; z++)
	{
		int n;
		cin >> n;
		int arr[3003];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int minsum = 19 * 1000 * 1000;
		int index = 0;
		for (size_t i = 0; i < n; i++)
		{
			int sum = 0;
			for (size_t j = 0; j < n; j++)
			{
				if (j==i)
				{
					continue;
				}
				else
				{
					int temp = arr[i] - arr[j];
					if (temp<0)
					{
						temp *= -1;
					}
					sum += temp;
				}
			}
			if (i==0)
			{
				minsum = sum;
			}
			if (sum<minsum)
			{
				minsum = sum;
				index = i;
			}
		}
		cout << minsum << endl;
	}
}
