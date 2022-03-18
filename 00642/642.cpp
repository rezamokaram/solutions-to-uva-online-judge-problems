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
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const ll MAX = 100000;
//
int main()
{
	vector<pair<string,string>> dic;
	string a;
	while (cin>>a)
	{
		if (a == "XXXXXX")break;
		string b = a;
		sort(a.begin(), a.end());
		dic.push_back(pair<string,string>(a, b));
	}
	sort(dic.begin(), dic.end());
	while (cin >> a)
	{
		if (a == "XXXXXX")break;
		sort(a.begin(), a.end());
		bool any = 0;
		for (size_t i = 0; i < dic.size(); i++)
		{
			if (a==dic[i].first)
			{
				cout << dic[i].second << endl;
				any = 1;
			}
		}
		if (!any)
		{
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;
	}
}
