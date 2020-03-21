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
int dig(ll x)
{
	int ans = 0;
	while (x>0)
	{
		ans++;
		x /= 10;
	}
	return ans;
}
//
int main()
{
	vector<string>list;
	char a;
	string str;
	while (cin.get(a))
	{
		if (a >= 'A' && a <= 'Z')
		{
			str += a + 32;
		}
		else if (a >= 'a' && a <= 'z')
		{
			str += a;
		}
		else
		{
			if (list.size()>=1)
			{
				if (str != "" && str!="\n")
				{
					list.push_back(str);
				}
			}
			else
			{
				if (str != "" && str != "\n")
				{
					list.push_back(str);
				}
			}
			str.clear();
		}
	}
	if (list.size() >= 1)
	{
		if (str != "")
		{
			list.push_back(str);
		}
	}
	else
	{
		list.push_back(str);
	}
	str.clear();
	sort(list.begin(), list.end());
	for (size_t i = 0; i < list.size(); i++)
	{
		if (i==0)
		{
			cout << list[i];
			cout << endl;
		}
		else if (list[i]!=list[i-1])
		{
			cout << list[i];
			cout << endl;
		}
		
		//cout << endl;
	}
}
