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
int main()
{
	int tc;
	cin >> tc;
	int de = 0;
	while (tc--)
	{
		de++;
		int n, p, q;
		cin >> n >> p >> q;
		vector<int>list;
		for (size_t i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			list.push_back(temp);
		}
		int w = 0;
		int ans = 0;
		sort(list.begin(), list.end());
		for (size_t i = 0; i < n; i++)
		{
			if (w+list[i]<=q)
			{
				w += list[i];
				ans++;
			}
		}
		int na = ans;
		if (p<ans)
		{
			na = p;
		}
		cout << "Case " << de << ": " << na << endl;
	}
}
