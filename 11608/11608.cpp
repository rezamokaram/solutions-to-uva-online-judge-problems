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
int gcd(int a, int b) { return(b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return(a*b / gcd(a, b)); }
//
int main()
{
	int n;
	int tc = 0;
	while (cin >> n && n > -1)
	{
		vector<int>list(12, 0), c(12);
		list[0] = n;
		for (size_t i = 0; i < 12; i++)
		{
			int temp;
			cin >> temp;
			if (i<11)
			{
				list[i + 1] += temp;
			}
		}
		cout << "Case " << ++tc << ":" << endl;
		for (int i = 0; i < 12; i++)
		{
			cin >> c[i];
			if (c[i]<=list[i])
			{
				cout << "No problem! :D" << endl;
				list[i] -= c[i];
			}
			else
			{
				cout << "No problem. :(" << endl;
			}
			if (i<11)
			{
				list[i + 1] += list[i];
			}
		}
	}
}
