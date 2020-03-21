#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
ll arr[10000];
//
bool ppair(string a, string b)
{
	string a1 = a + b;
	string a2 = b + a;
	for (size_t i = 0; i < a1.length(); i++)
	{
		if (a2[i]>a1[i])
		{
			return false;
		}
		else if (a1[i]>a2[i])
		{
			return true;
		}
	}
	return false;
}
//
ll vos(string a)
{
	ll val = 0;
	for (size_t i = 1; i <= a.length(); i++)
	{
		val += (a[i - 1] - '0')*(a.length()-i);
		val -= (10*i);
	}
	return val;
}
//
int main()
{
	int tc;
	while (cin >> tc && tc)
	{
		vector<string>list;
		for (size_t i = 0; i < tc; i++)
		{
			string a;
			cin >> a;
			list.push_back(a);
			arr[i] = vos(a);
		}
		for (size_t i = 0; i < tc; i++)
		{
			for (size_t j = 0; j < tc - i - 1; j++)
			{
				bool f = ppair(list[j], list[j + 1]);
				if (f)
				{
					swap(list[j], list[j + 1]);
				}
			}
		}
		for (int i = tc-1; i >= 0; i--)
		{
			cout << list[i];
		}
		cout << endl;
	}
}
