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
bool arr[2009] = { 0 };
void f()
{
	arr[0] = 1;
	arr[1] = 1;
	for (size_t i = 2; i < 2009; i++)
	{
		if (arr[i])
			continue;
		for (size_t j = i+i; j < 2009; j+=i)
		{
			arr[j] = 1;
		}
	}
}
bool ip(int n)
{
	return (arr[n]) ? 0 : 1;
}
int main()
{
	f();
	int tc;
	cin >> tc;
	cin.ignore();
	int c = 1;
	while (tc--)
	{
		string str;
		getline(cin, str);
		sort(str.begin(), str.end());
		string ans;
		char t = '?';
		int num = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (t!=str[i])
			{
				if (ip(num))ans += t;
				t = str[i];
				num = 1;
			}
			else
			{
				num++;
			}
			if (i==str.size()-1)
			{
				if (ip(num))ans += t;
			}
		}
		cout << "Case " << c++ << ": ";
		if (ans.length())
		{
			cout << ans << endl;
		}
		else
		{
			cout << "empty" << endl;
		}
	}
}
