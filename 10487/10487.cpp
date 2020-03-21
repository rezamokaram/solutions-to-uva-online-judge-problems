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
	int n, m;
	int tc = 0;
	while (cin >> n && n)
	{
		vector<int>num(n);
		for (size_t i = 0; i < n; i++)
			cin >> num[i];
		set<int>sub;
		for (size_t i = 0; i < n; i++)
			for (size_t j = i+1; j < n; j++)
				sub.insert(num[i] + num[j]);
		num.clear();
		cout << "Case " << ++tc << ":" << endl;
		cin >> m;
		while (m--)
		{
			int x;
			cin >> x;
			set<int>::iterator it = sub.lower_bound(x);
			int best = *it;
			if (it == sub.end())
			{
				it--;
				best = *it;
			}
			else if (it != sub.begin())
			{
				it--;
				if (abs(x - best) > abs(x - *it))
					best = *it;
			}
			cout << "Closest sum to " << x << " is " << best << "." << endl;
		}
	}
}
