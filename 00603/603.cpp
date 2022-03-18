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
vector<int>wait,parked,org;
vector<bool>vc;
int et(int pos, int come)
{
	if (come <= pos)
	{
		return (pos - come);
	}
	return (pos + (20 - come));
}
pair<int,int> findn(int pos)
{
	int lowest = 21, index = 21;
	for (size_t i = 0; i < wait.size(); i++)
	{
		if (vc[i])
		{
			int ett = et(pos, wait[i]);
			if (lowest>ett)
			{
				lowest = ett;
				index = i;
			}
		}
	}
	return pair<int, int>(index, lowest);
}
int rmn(string s)
{
	int number = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		number *= 10;
		number += s[i] - '0';
	}
	return number;
}
void move(int d)
{
	for (size_t i = 0; i < wait.size(); i++)
	{
		if (vc[i])
		{
			wait[i] += d;
			if (wait[i] > 20)wait[i] -= 20;
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	bool kk = 0;
	while (tc--)
	{
		wait.clear();
		vc.clear();
		parked.clear();
		org.clear();
		int w;
		while (cin>>w && w!=99)
		{
			wait.push_back(w);
			vc.push_back(1);
			parked.push_back(0);
			org.push_back(w);
		}
		string line;
		getline(cin, line);
		while (getline(cin, line))
		{
			if (line=="")
			{
				break;
			}
			int emp = rmn(line);
			pair<int,int> n = findn(emp);
			int ind = n.first, des = n.second;
			move(des);
			vc[ind] = 0;
			parked[ind] = emp;
		}
		if (kk)cout << endl;
		kk = 1;
		for (size_t i = 0; i < org.size(); i++)
		{
			cout << "Original position " << org[i];
			if (parked[i])
			{
				cout << " parked in " << parked[i] << endl;
			}
			else
			{
				cout << " did not park" << endl;
			}
		}
		
	}
}
