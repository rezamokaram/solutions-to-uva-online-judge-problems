#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int a, b,n;
	cin >> n;
	for (int z = 0 ; z < n ; z++)
	{
		cin >> a >> b;
		if (b%a==0)
		{
			cout << a << " " << b << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}
