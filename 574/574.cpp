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
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<vector<int>>subs;
vector<int>num;
int sumall, n;
void bt(vector<int>list,int sum,int index)
{
	if (sum==sumall || index==n)
	{
		if (sum == sumall) { subs.push_back(list); }
		return;
	}
	list.push_back(num[index]);
	bt(list, sum + num[index], index + 1);
	list.pop_back();
	bt(list, sum, index + 1);
}
//
bool ui(int a, int b)
{
	return (a > b);
}
//
int main()
{
	while (cin >> sumall >> n && n && sumall)
	{
		num.clear();
		subs.clear();
		for (size_t i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			num.push_back(temp);
		}
		sort(num.begin(), num.end(), ui);
		vector<int>list;
		bt(list, 0, 0);
		sort(subs.begin(), subs.end());
		cout << "Sums of " << sumall << ":" << endl;
		for (int i = subs.size()-1; i >= 0; i--)
		{
			if (i != subs.size() - 1)
			{
				if (subs[i]==subs[i+1])
					continue;
			}
			for (int j = 0; j < subs[i].size(); j++)
			{
				if (j)
				{
					cout << "+";
				}
				cout << subs[i][j];
			}
			cout << endl;
		}
		if (subs.size() == 0)
		{
			cout << "NONE" << endl;
		}
	}
}
