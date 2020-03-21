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
	vector<int>pt(21, 1);
	for (size_t i = 1; i < 21; i++)
	{
		pt[i] = pt[i - 1] * 2;
	}
	int n;
	while (cin >> n && n)
	{
		int index = 0;
		while (n>=pt[index])
		{
			index++;
		}
		int ans = 0;
		int how = n - pt[index-1];
		if (how==0)
		{
			ans = n;
		}
		else
		{
			ans = (how) * 2;
		}
		cout << "Discarded cards:";
		if (n != 1)
		{
			cout << " ";
			vector<int>li;
			for (size_t i = 1; i <= n; i++)
			{
				li.push_back(i);
			}
			for (size_t i = 0; i < li.size() - 1; i++)
			{
				if (li[i] != 1)
				{
					cout << ", ";
				}
				cout << li[i];
				i++;
				li.push_back(li[i]);
			}
		}
		cout << endl << "Remaining card: " << ans << endl;
	}
}
