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
	int index = 0;
	for (size_t i = 0; i < al.length(); i++)
	{
		string temp;
		temp += al[i];
		ma[temp] = ++index;
	}
	for (size_t i = 0; i < al.length(); i++)
	{
		for (size_t j = i + 1; j < al.length(); j++)
		{
			string temp;
			temp += al[i];
			temp += al[j];
			ma[temp] = ++index;
		}
	}
	for (size_t i = 0; i < al.length(); i++)
	{
		for (size_t j = i + 1; j < al.length(); j++)
		{
			for (size_t z = j + 1; z < al.length(); z++)
			{
				string temp;
				temp += al[i];
				temp += al[j];
				temp += al[z];
				ma[temp] = ++index;
			}
		}
	}
	for (size_t i = 0; i < al.length(); i++)
	{
		for (size_t j = i + 1; j < al.length(); j++)
		{
			for (size_t z = j + 1; z < al.length(); z++)
			{
				for (size_t k = z + 1; k < al.length(); k++)
				{
					string temp;
					temp += al[i];
					temp += al[j];
					temp += al[z];
					temp += al[k];
					ma[temp] = ++index;
				}
			}
		}
	}
	for (size_t i = 0; i < al.length(); i++)
	{
		for (size_t j = i + 1; j < al.length(); j++)
		{
			for (size_t z = j + 1; z < al.length(); z++)
			{
				for (size_t k = z + 1; k < al.length(); k++)
				{
					for (size_t p = k + 1; p < al.length(); p++)
					{
						string temp;
						temp += al[i];
						temp += al[j];
						temp += al[z];
						temp += al[k];
						temp += al[p];
						ma[temp] = ++index;
					}
				}
			}
		}
	}
	string str;
	while (cin >> str)
	{
		if (ma.count(str))
		{
			cout << ma[str] << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}
