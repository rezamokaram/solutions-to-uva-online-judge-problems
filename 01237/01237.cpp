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
	while (tc--)
	{
		vector<string>name;
		vector<int>lowest;
		vector<int>highest;
		int v;
		cin >> v;
		while (v--)
		{
			string nname;
			int nl, nh;
			cin >> nname >> nl >> nh;
			name.push_back(nname);
			lowest.push_back(nl);
			highest.push_back(nh);
		}
		int ans;
		cin >> ans;
		while (ans--)
		{
			int p;
			cin >> p;
			string nname;
			int ans = 0;
			for (size_t i = 0; i < name.size(); i++)
			{
				if (p >= lowest[i] && p <= highest[i])
				{
					ans++;
					nname = name[i];
				}
			}
			if (ans == 1)
			{
				cout << nname << endl;
			}
			else
			{
				cout << "UNDETERMINED" << endl;
			}
		}
		if (tc)
		{
			cout << endl;
		}
	}
}
