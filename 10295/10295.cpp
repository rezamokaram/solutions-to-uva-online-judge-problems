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
map<string, ll>ma;
string al = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	int m, n;
	cin >> m >> n;
	for (size_t i = 0; i < m; i++)
	{
		string a;
		ll b;
		cin >> a >> b;
		ma[a] = b;
	}
	while (n--)
	{
		llu salary = 0;
		string str;
		while (cin >> str && str != ".")
		{
			if (ma.count(str))
			{
				salary += ma[str];
			}
		}
		cout << salary << endl;
	}
}
