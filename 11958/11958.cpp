#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int tc;
	cin >> tc;
	int test = 0;
	while (tc--)
	{
		test++;
		int k;
		cin >> k;
		int c, temp;
		char sine;
		cin >> c >> sine >> temp;
		c *= 60;
		c += temp;
		int min = 10000 * 60;
		for (size_t i = 0; i < k; i++)
		{
			int time;
			cin >> temp >> sine >> time;
			time += (temp * 60);
			cin >> temp;
			if (time < c)
			{
				time += 1440;
			}
			time += temp;
			if (time < min)
			{
				min = time;
			}

		}
		cout << "Case " << test << ": " << min - c << endl;
	}
}
