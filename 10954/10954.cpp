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
bool ui(int a, int b)
{
	return (a > b) ? true : false;
}
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		priority_queue<int, vector<int>, greater<int>> arr;
		for (size_t i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			arr.push(temp);
		}
		ll ans = 0;
		while (arr.size()>1)
		{
			int now = arr.top();
			arr.pop();
			now += arr.top();
			arr.pop();
			arr.push(now);
			ans += now;
		}
		cout << ans << endl;
	}
}
