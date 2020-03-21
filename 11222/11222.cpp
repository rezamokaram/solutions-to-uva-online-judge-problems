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
map<string, int>ma;
string al = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	int tc;
	cin >> tc;
	int c = 1;
	while (tc--)
	{
		vector<vector<int>>list(3);
		int arr[10000] = { 0 };
		for (size_t i = 0; i < 3; i++)
		{
			int n;
			cin >> n;
			for (size_t j = 0; j < n; j++)
			{
				int temp;
				cin >> temp;
				list[i].push_back(temp);
			}
		}
		for (size_t i = 0; i < 3; i++)
		{
			sort(list[i].begin(), list[i].end());
			for (size_t j = 0; j < list[i].size(); j++)
			{
				if (j)
				{
					if (list[i][j] != list[i][j-1])
					{
						arr[list[i][j]]++;
					}
					continue;
				}
				arr[list[i][j]]++;
			}
		}
		vector<vector<int>>ans(3);
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < list[i].size(); j++)
			{
				if (arr[list[i][j]]==1)
				{
					if (j)
					{
						if (list[i][j]!=list[i][j-1])
						{
							ans[i].push_back(list[i][j]);
						}
						continue;
					}
					ans[i].push_back(list[i][j]);
				}
			}
		}
		int max = 0;
		for (size_t i = 0; i < 3; i++)
		{
			if (ans[i].size() > max)
			{
				max = ans[i].size();
			}
		}
		cout << "Case #" << c++ << ":\n";
		for (size_t i = 0; i < 3; i++)
		{
			if (ans[i].size() == max)
			{
				cout << i + 1 << " " << ans[i].size();
				for (size_t j = 0; j < ans[i].size(); j++)
				{
					cout << " " << ans[i][j];
				}
				cout << endl;
			}
		}
	}
}
