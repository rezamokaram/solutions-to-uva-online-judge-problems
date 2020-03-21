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
int ne(int a)
{
	if (a == 0)
	{
		return 9;
	}
	return a - 1;
}
string number;
vector<int>arr(10, 0);
void build(int index, int how)
{
	for (index = 0; index < number.length(); index++)
	{
		if (how == 1)
		{
			arr[number[index] - '0']--;
		}
		if (arr[number[index] - '0'] < 2 && how == 0)
		{
			arr[number[index] - '0']++;
			how = 0;
			continue;
		}
		int dig = ne(number[index] - '0');
		while (arr[dig] >= 2)
		{
			dig = ne(dig);
		}
		if (dig > number[index] - '0')
		{
			number[index] = dig + '0';
			for (size_t j = index + 1; j < number.length(); j++)
			{
				number[j] = '9';
			}
			index -= 2;
			how = 1;
			continue;
		}
		else
		{
			number[index] = dig + '0';
			arr[dig]++;
			for (size_t j = index + 1; j < number.length(); j++)
			{
				number[j] = '9';
			}
			how = 0;
			continue;
		}
	}
	return;
}
bool check()
{
	int a[10] = { 0 };
	for (size_t i = 0; i < number.length(); i++)
	{
		a[number[i] - '0']++;
		if (a[number[i] - '0'] > 2)
		{
			return 0;
		}
	}
	return 1;
}
llu com(string str)
{
	llu res = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i)
		{
			res *= 10;
		}
		res += str[i] - '0';
	}
	return res;
}
string les()
{
	string temp = "99887766554433221100";
	string res;
	for (size_t i = 0; i < number.length() - 1; i++)
	{
		res.push_back(temp[i]);
	}
	return res;
}
int main()
{
	while (cin >> number)
	{
		for (size_t i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
		string here = number;
		build(0, 0);
		if (com(here) < com(number) || !check())
		{
			string num = les();
			cout << num << endl;
		}
		else
		{
			bool ff = 0;
			for (size_t i = 0; i < number.size(); i++)
			{
				if (ff || number[i] != '0')
				{
					cout << number[i];
					ff = 1;
				}
			}
			cout << endl;
		}
	}
}
