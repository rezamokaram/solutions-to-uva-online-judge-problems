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
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int const big = 100009;
int main()
{
	int a, b;
	while (cin >> a >> b && a && b)
	{
		bool aa[big] = { 0 }, bb[big] = { 0 };
		for (size_t i = 0; i < a; i++)
		{
			int temp;
			cin >> temp;
			aa[temp] = 1;
		}
		for (size_t i = 0; i < b; i++)
		{
			int temp;
			cin >> temp;
			bb[temp] = 1;
		}
		int aaa = 0, bbb = 0;
		for (size_t i = 0; i < big; i++)
		{
			if (aa[i] && !bb[i])
			{
				aaa++;
			}
			if (bb[i] && !aa[i])
			{
				bbb++;
			}
		}
		if (aaa>bbb)
		{
			cout << bbb << endl;
		}
		else
		{
			cout << aaa << endl;
		}
	}
}
