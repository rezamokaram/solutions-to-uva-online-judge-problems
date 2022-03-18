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
	int P;
	while (cin>>P)
	{
		int b = 0, e = 0;
		string s;
		while (1)
		{
			char c;
			cin >> c;
			if (c == '(')
				b++;
			else if (c == ')')
				e++;
			s += c;
			/*if (c=='(' || c==')')
				s += ' ';*/
			if (b == e)
				break;
		}
		int bb=0;
		stack<int> arr;
		vector<int> ans;
		string root = "1234";
		ll rv = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			//root check
			root[0] = root[1];
			root[1] = root[2];
			root[2] = root[3];
			root[3] = s[i];
			if (root=="()()")
			{
				ans.push_back(rv);
			}
			//read a number
			if (s[i]=='-' || (s[i] >= '0' && s[i] <= '9'))
			{
				int number = 0,now=0,mt=1;
				if (s[i]=='-')
				{
					mt = -1;
					i++;
				}
				while (s[i] >= '0' && s[i] <= '9')
				{
					now = s[i] - '0';
					number *= 10;
					number += now;
					i++;
				}
				number *= mt;
				arr.push(number);
				rv += number;
				i--;
			}
			else if (s[i]=='(')
			{
				bb++;
			}
			else if(s[i]==')')
			{
				bb--;
				if (root[2]==')')
				{
					int number = arr.top();
					arr.pop();
					rv -= number;
				}
			}

		}
		//find
		bool ok = 0;
		for (size_t i = 0; i < ans.size(); i++)
		{
			if (P == ans[i]) {
				ok = 1; break;
			}
		}
		if (ok)cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
