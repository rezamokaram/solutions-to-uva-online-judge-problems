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
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<int>list;
		while (n--)
		{
			int sum = 0;
			string temp;
			cin >> temp;
			sum += temp.length();
			if (sum<25)
			{
				cin >> temp;
				sum += temp.length();
			}
			list.push_back(sum);
		}
		int ans = 0;
		if (list.size() <= 1)
		{
			cout << 0 << endl;
			continue;
		}
		sort(list.begin(), list.end());
		for (size_t i = 0; i < list.size() - 1; i++)
		{
			ans += list[list.size() - 1] - list[i];
		}
		cout << ans << endl;
	}
}
