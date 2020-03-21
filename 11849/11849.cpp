#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<int>first;
int se(int number, int start, int end)
{
	if (first[(start + end) / 2] == number)
	{
		return (start + end) / 2;
	}
	if (start == end)
	{
		return -1;
	}
	if (first[(start + end) / 2] > number)
	{
		return se(number, start, (start + end) / 2);
	}
	else
	{
		return se(number, ((start + end)+1) / 2, end);
	}
}
int main()
{
	int a, b;
	while (cin>>a>>b && a && b)
	{
		first.clear();
		for (size_t i = 0; i < a; i++)
		{
			int temp;
			cin >> temp;
			first.push_back(temp);
		}
		sort(first.begin(), first.end());
		int ans = 0;
		for (size_t i = 0; i < b; i++)
		{
			int temp;
			cin >> temp;
			if (se(temp,0,a-1)!=-1)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
}
