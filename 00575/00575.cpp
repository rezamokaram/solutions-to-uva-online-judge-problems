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
	string a;
	while (cin >> a)
	{
		if (a=="0")
		{
			break;
		}
		int len = a.length();
		long long int sum = 0, size;
		int len1 = len;
		for (size = 0; size < len ; size++)
		{
			int temp = a[size] - '0';
			sum += temp * (pow(2, len1) - 1);
			len1--;
		}
		cout << sum << endl;

	}
}
