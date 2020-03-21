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
	ll number;
	while (cin >> number)
	{
		if (number==0)
		{
			break;
		}
		int arr[10000];
		for (size_t i = 0; i < number; i++)
		{
			cin >> arr[i];
			if (i>0)
			{
				arr[i] += arr[i - 1];
			}
		}

		ll msum = 0;
		int sum = 0;
		for (int i = number-1; i >= 0; i--)
		{
			int temp = arr[i];
			if (temp > msum)
			{
				msum = temp;
			}
			for (size_t j = 0; j < i; j++)
			{
				temp = arr[i] - arr[j];
				if (temp>msum)
				{
					msum = temp;
				}
			}
		}

		if (msum <= 0)
		{
			cout << "Losing streak." << endl;
		}
		else
		{
			cout << "The maximum winning streak is " << msum << "." << endl;
		}
	}
}
