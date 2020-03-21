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
	int h, l;
	while (cin >>h && h)
	{
		cin >> l;
		vector<int>list;
		int temp;
		cin >> temp;
		int ans = h - temp;
		list.push_back(temp);
		for (size_t i = 1; i < l; i++)
		{
			cin >> temp;
			list.push_back(temp);
			if (temp<h)
			{
				if (temp<list[i-1])
				{
					ans += list[i - 1] - temp;
				}
			}
		}
		cout << ans << endl;
	}
}
