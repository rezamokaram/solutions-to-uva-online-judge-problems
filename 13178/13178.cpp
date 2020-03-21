#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	long long int n;
	cin >> n;
	for (long long int i = 0; i < n; i++)
	{
		long long unsigned int a,temp;
		cin >> a;
		temp = a % 3;
		if (temp==0 || temp==2)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
}
