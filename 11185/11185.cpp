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
	long long int n;
	while (cin >> n)
	{
		if (n < 0)
		{
			break;
		}
		else if (n==0)
		{
			cout << 0 << endl;
			continue;
		}
		int i, arr[10000];
		for (i = 0; n > 0 ; i++)
		{
			arr[i] = n % 3;
			n /= 3;
		}
		for (int j = i - 1 ; j >= 0 ; j-- )
		{
			cout << arr[j];
		}
		cout << endl;
	}
}
