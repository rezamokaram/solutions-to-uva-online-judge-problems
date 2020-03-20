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
int main()
{
	vector<llu>p(22);
	p[0] = 1;
	for (size_t i = 1; i <= 21; i++)
		p[i] = p[i - 1] * 2;
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll depth, b;
		cin >> depth >> b;
		ll ans = 1;
		while (ans + ans < p[depth])
		{
			ans += ans;
			if (b % 2 == 0)ans++;
			b = (b + 1) / 2;
		}
		cout << ans << endl;
	}
	cin >> tc;
}
