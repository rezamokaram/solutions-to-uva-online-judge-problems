#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	int arr[9];
	
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8])
	{
		//
		int sumall = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7] + arr[8];
		//
		int sum[6];
		sum[0] = arr[0] + arr[5] + arr[7];
		sum[1] = arr[0] + arr[4] + arr[8];
		sum[2] = arr[2] + arr[3] + arr[7]; 
		sum[3] = arr[2] + arr[4] + arr[6];
		sum[4] = arr[1] + arr[3] + arr[8]; 
		sum[5] = arr[1] + arr[5] + arr[6];
		//
		int max = -1;
		int index;
		for (size_t i = 0; i < 6; i++)
		{
			if (sum[i]>max)
			{
				max = sum[i];
				index = i;
			}
		}
		//
		if (index == 0)
		{
			cout << "BCG ";
		}
		else if (index == 1)
		{
			cout << "BGC ";
		}
		else if (index == 2)
		{
			cout << "CBG ";
		}
		else if (index == 3)
		{
			cout << "CGB ";
		}
		else if (index == 4)
		{
			cout << "GBC ";
		}
		else if (index == 5)
		{
			cout << "GCB ";
		}
		cout << (sumall - max) << endl;
	}
}
