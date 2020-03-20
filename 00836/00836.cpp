//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const ll MAX = 9999999999;
//
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	cin.ignore();
	bool f = 0;
	while (n--)
	{
		int res = 0;
		vector<string>list;
		string s;
		while (getline(cin, s) && s.size())
			list.push_back(s);
		int arr[26][26] = { 0 };
		for (size_t i = 0; i < list.size(); i++)
		{
			int c = 0;
			for (int j = list.size() - 1; j >= 0; j--)
			{
				if (list[i][j] == '0')c = 0;
				else c++;
				arr[i][j] = c;
			}
		}
		//
		int ss = list.size();
		for (int i = 0; i < ss; i++)
		{
			for (int j = 0; j < ss; j++)
			{
				for (int z = j; z < ss; z++)
				{
					bool ff = 1;
					for (int k = i; k < ss; k++)
					{
						if (arr[k][j]<(z-j+1))
						{
							ff = 0;
							break;
						}
						if (ff)
						{
							res = max(res, ((z-j + 1)*(k-i + 1)));
						}
					}
					
				}
			}
		}
		/*for (size_t i = 0; i < list.size(); i++)
		{
			int mn = list.size() + 1;
			int mm = 0;
			for (size_t j = 0; j < list.size(); j++)
			{
				if (arr[j][i])
				{
					mm++;
					mn = min(mn, arr[j][i]);
					res = max(res, mn*mm);
				}
				else
				{
					mn = list.size() + 1;
					mm = 0;
				}
			}
		}*/
		//
		if (f)cout << endl;
		cout << res << endl;
		f = 1;
	}
}
