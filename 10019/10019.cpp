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
int dtob(int num)
{
	int ans = 0;
	while (num)
	{
		if (num%2==1)
		{
			ans++;
		}
		num /= 2;
	}
	return ans;
}
int htob(int num)
{
	int ans = 0;
	while (num)
	{
		int dig = num % 10;
		num /= 10;
		if (dig>=8)
		{
			ans++;
			dig -= 8;
		}
		if (dig >= 4)
		{
			ans++;
			dig -= 4;
		}
		if (dig >= 2)
		{
			ans++;
			dig -= 2;
		}
		if (dig >= 1)
		{
			ans++;
			dig -= 1;
		}
	}
	return ans;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << dtob(n) << " " << htob(n) << endl;
	}
}
