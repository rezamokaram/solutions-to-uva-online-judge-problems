#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int n;
	while (cin >> n)
	{
		int arr[10000];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		ll msum;
		cin >> msum;
		int indexa = 0, indexb = 0;
		for (size_t i = 0; i < n-1; i++)
		{
			for (size_t j = i+1; j < n; j++)
			{
				if (arr[i]+arr[j]==msum)
				{
					indexa = i;
					indexb = j;
				}
			}
		}
		cout << "Peter should buy books whose prices are " << arr[indexa] << " and " << arr[indexb] << "." << endl << endl;
	}
}
