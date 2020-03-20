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
using namespace std;
//
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 9999999999 + 1;
typedef pair<ll, pair<int, int>> edg;
struct edge
{
	ll v, des;
	edge(ll vv, ll dd)
	{
		v = vv, des = dd;
	}
	bool operator >(const edge & sec) const
	{
		return(v > sec.v);
	}
};
//
bool islet(char a)
{
	return ((a >= 'a' && a <= 'z') || (a >= 'A'&&a <= 'Z'));
}
int main()
{
	string str, word;
	vector<string>li;
	while (getline(cin, str) && str != "#")
		li.push_back(str);
	bool hyp = 0, wh = 0;
	for (size_t i = 0; i < li.size(); i++)
	{
		for (size_t j = 0; j < li[i].size(); j++)
		{
			if (islet(li[i][j]))
				word += li[i][j];
			else if (li[i][j]==' ')
			{
				cout << word;
				if (wh)
					cout << endl;
				cout << " ";
				hyp = 0;
				word.clear();
				wh = 0;
			}
			else if (li[i][j]=='-' && j && islet(li[i][j-1]) && j==li[i].size()-1)
				hyp = 1;
		}
		if (!hyp)
			cout << word, word.clear();
		else
			wh = 1;
		cout << endl;
		hyp = 0;
	}
}
