//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
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
#define all(X) X.begin(),X.end()
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const ll MAX = 100000;

//
int main()
{
	int tc;
	cin >> tc;
	bool ff = 0;
	while (tc--)
	{
		if (ff)cout << endl;
		ff = 1;
		int n;
		cin >> n;
		vector<string>can(n);
		vector<bool>el(n);
		getline(cin, can[0]);
		for (size_t i = 0; i < n; i++)
		{
			getline(cin,can[i]);
			el[i] = 1;
		}
		vector<vector<int>>list;
		vector<int>index;
		string line = "";
		int gam = 0;
		while (getline(cin,line) && line!="")
		{
			list.push_back(vector<int>(n));
			int j = 0,number=0;
			for (size_t i = 0; i < line.length(); i++)
			{
				if (line[i]>='0' && line[i]<='9')
				{
					number *= 10;
					number += line[i] - '0';
				}
				if (line[i] == ' ' || i == line.length() - 1)
				{
					list[gam][j] = number;
					number = 0;
					j++;
				}
			}
			index.push_back(0);
			gam++;
		}
		//end inp
		//process
		int nim = (gam / 2) + 1,eliminated=0,winner=-1,kp=0;
		bool select = 0,tied=0;
		while (eliminated<n && !select && !tied && kp<n)
		{
			kp++;
			int lowest = gam + 1,highest=-1;
			vector<int>emt(n, 0);
			for (size_t j = 0; j < index.size(); j++)
			{
				int that = list[j][index[j]]-1;
				if (that >= n)
					continue;
				emt[that] += 1;
			}
			for (size_t j = 0; j < n; j++)
			{
				if(el[j])lowest = min(lowest, emt[j]);
				if (el[j])highest = max(highest, emt[j]);
				if (emt[j]>=nim)
				{
					select = 1;
					winner = j;
					break;
				}
			}
			if (lowest == highest)
			{
				tied = 1;
				break;
			}
			//eliminating
			for (size_t i = 0; i < n; i++)
			{
				if (emt[i]==lowest && el[i])
				{
					el[i] = 0;
					eliminated++;
				}
			}
			int qq = 1;
			//bool nch = 0;
			for (size_t j = 0; j < index.size() && !select; j++)
			{
				int that = list[j][index[j]]-1;
				if (that >= n)
					continue;
				
				while (!el[that] && index[j]<n)
				{
					//nch = 1;
					index[j]++;
					if(index[j]<n)that = list[j][index[j]] - 1;
					
				}

			}
			/*if (!nch)
			{
				tied = 1;
				break;
			}*/
			int qqq = 1;
			// end of eling
		}
		int rpo = 0;
		//output
		if (select)
		{
			cout << can[winner] << endl;
		}
		else 
		{
			for (size_t i = 0; i < can.size(); i++)
			{
				if(el[i])cout << can[i] << endl;
			}
		}
	}
}
