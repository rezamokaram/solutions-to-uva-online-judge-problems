//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdio.h>
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
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
vector<int>list, pp, par, inn;
void printt(int d)
{
	
	if(pp[d]!=d)printt(pp[d]);
	cout << par[d] << endl;
}
//
int main()
{
	int tc;
	bool f = 0;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--)
	{
		list.clear();
		inn.clear();
		pp.clear();
		par.clear();
		if (f)cout << endl;
		f = 1;
		string str;

		int i = 0;
		while (getline(cin,str)&&str.size())
		{
			pp.push_back(i);
			int temp = stoi(str);
			par.push_back(temp);
			int pos = lower_bound(list.begin(), list.end(), temp) - list.begin();
			if (pos==list.size())
			{
				if (list.size())
				{
					pp[i] = inn[pos - 1];
				}
				list.push_back(temp);
				inn.push_back(i);
				
			}
			else //if(pos==list.size()-1)
			{
				if (temp<list[pos])
				{
					inn[pos] = i;
					list[pos] = temp;
					if(pos)pp[i] = inn[pos - 1];
				}
			}
			++i;
		}
		cout << "Max hits: " << list.size() << endl;
		printt(inn[inn.size() - 1]);
	}
}
