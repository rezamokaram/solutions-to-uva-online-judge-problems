# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
# include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
int main()
{
	ll n;
	while (cin >>n && n)
	{
		vector<int>car(n), pos(n, 0);
		bool f = 1;
		for (size_t i = 0; i < n; i++)
		{
			int num, p;
			cin >> num >> p;
			if (i + p >= 0 && i + p < n)
			{
				if (pos[i + p])f = 0;
				pos[i + p] = num;
			}
			else f = 0;
		}
		if (f)
		{
			for (size_t i = 0; i < n; i++)
			{
				if (i)cout << " ";
				cout << pos[i];
			}
			cout << endl;
		}
		else cout << -1 << endl;
	}
}
