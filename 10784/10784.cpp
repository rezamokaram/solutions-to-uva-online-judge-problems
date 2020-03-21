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
	for (size_t i = 1; cin >> n; i++)
	{
		if (n==0)
		{
			break;
		}
		if (n<3)
		{
			cout << "Case " << i << ": " << 4 << endl;
			continue;
		}
		if (n<5)
		{
			cout << "Case " << i << ": " << 5 << endl;
			continue;
		}
		for (llu j = sqrt(2*n); true ; j++)
		{
			if ((j-3)*j>=2*n)
			{
				cout << "Case " << i << ": " << j << endl;
				break;
			}
		}
	}
}
