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
	int n;
	while (cin >> n && n)
	{
		vector<string>m(5);
		map<string, int>list;
		int max = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
			string temp;
			sort(m.begin(), m.end());
			temp = m[0] + m[1] + m[2] + m[3] + m[4];
			if (list.count(temp))
			{
				list[temp]++;
			}
			else
			{
				list[temp] = 1;
			}
			if (list[temp]>max)
			{
				max = list[temp];
			}
		}
		int ans = 0;
		for (map<string,int>::iterator i = list.begin(); i != list.end(); i++)
		{
			if (i-> second == max)
			{
				ans+=i->second;
			}
		}
		cout << ans << endl;
	}
}
