#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		bool f = 1;
		int a, b;
		cin >> a >> b;
		int def = a - b;
		for (size_t i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			if (a-b!=def)
			{
				f = 0;
			}
		}
		if (f)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		if (tc)
		{
			cout << endl;
		}
	}
}
