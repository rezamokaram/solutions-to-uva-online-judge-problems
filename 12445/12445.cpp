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
int sumall,len;
vector<int>list;
bool f = 0;
void bt(int sum,int index)
{
	if (sum == sumall)
	{
		f = 1;
		return;
	}
	if (f || index >= len)
	{
		return;
	}
	int number = list[index];
	bt(sum + number, index + 1);
	bt(sum, index + 1);
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		list.clear();
		f = 0;
		cin >> sumall >> len;
		for (size_t i = 0; i < len; i++)
		{
			int temp;
			cin >> temp;
			list.push_back(temp);
		}
		bt(0, 0);
		if (f)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
