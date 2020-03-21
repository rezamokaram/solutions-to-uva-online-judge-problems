#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;

int main()
{
	llu n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		llu j = sqrt(n);
		if (j*j==n)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
