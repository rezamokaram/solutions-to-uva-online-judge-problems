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
	int n, t;
	int q = 1;
	while (cin >> n >> t && n && t)
	{
		cout << "CASE# " << q << ":" << endl;
		q++;
		int arr[100000];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (size_t i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			bool f = false;
			for (size_t j = 0; j < n; j++)
			{
				if (arr[j]==x)
				{
					cout << x << " found at " << j + 1 << endl;
					f = true;
					break;
				}
			}
			if (!f)
			{
				cout << x << " not found" << endl;
			}
		}
	}
}
