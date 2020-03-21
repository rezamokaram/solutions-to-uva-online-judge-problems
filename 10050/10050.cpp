#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
string al = "abcdefghijklmnopqrstuvwxyz";
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
//
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int day, p;
		cin >> day >> p;
		vector<int>ints;
		int ppp = p;
		while (p--)
		{
			int temp;
			cin >> temp;
			ints.push_back(temp);
		}
		//process
		ll ans = 0;
		for (size_t i = 1; i <= day; i++)
		{
			if (i % 7 == 6 || i % 7 == 0)
				continue;
			bool f = false;
			for (size_t j = 0; j < ints.size(); j++)
			{
				if (i%ints[j]==0)
				{
					f = true;
					break;
				}
			}
			if (f)
				ans++;
		}
		//
		cout << ans << endl;
	}
}
