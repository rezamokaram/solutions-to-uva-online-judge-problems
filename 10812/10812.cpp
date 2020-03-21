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
	int tc;
	cin >> tc;
	for (size_t z = 0; z < tc; z++)
	{
		ll a, b;
		cin >> a >> b;
		ll temp = (a/2)+(b/2)+1;
		if (b>a)
		{
			cout << "impossible" << endl;
			continue;
		}
		while (true)
		{
			if (temp+temp-b==a)
			{
				cout << temp << " " << temp - b << endl;
				break;
			}
			else if (temp+temp-b<a)
			{
				cout << "impossible" << endl;
				break;
			}
			temp--;
		}
	}
}
