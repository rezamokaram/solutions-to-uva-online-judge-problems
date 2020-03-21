#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	int tc;
	cin >> tc;
	for (size_t z = 0; z < tc; z++)
	{
		int n;
		cin >> n;
		int arr[10000];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int cptain = (n / 2);
		cout << "Case " << z + 1 << ": " << arr[cptain] << endl;
	}
}
