#include <iostream>
#include <cstdio>
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
	for (size_t i = 0; i < tc; i++)
	{
		float a, b;
		cin >> a >> b;
		double temp1 = 9.0 / 5.0;
		double temp = a * temp1 + 32;
		temp += b;
		temp1 = 5.0 / 9.0;
		a = (temp - 32)*temp1;
		cout << "Case " << i + 1 << ": " << fixed << setprecision(2) << a << endl;
	}
}
