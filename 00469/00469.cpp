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
int parent[30011], num[30011];
void sset(int n)
{
	for (size_t i = 0; i < n+1; i++)
		parent[i] = i,num[i]=1;
}
int gp(int n)
{
	return(parent[n] == n ? n : parent[n] = gp(parent[n]));
}
bool isch(char a)
{
	return (a == 'L' || a == 'W');
}
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	bool f = 0;
	while (tc--)
	{
		if (f)cout << endl;
		f = 1;
		vector<pair<int, int>>li;
		string str;
		int ii = 0;
		while (getline(cin,str) && isch(str[0]))
		{
			for (int j = 0; j < str.size(); j++)
			{
				char a = str[j];
				if (a=='W')
				{
					li.push_back(pair<int, int>(ii, j));
				}
			}
			++ii;
		}
		sset(li.size());
		for (size_t i = 0; i < li.size(); i++)
		{
			int x = gp(i);
			for (size_t j = 0; j < li.size(); j++)
			{
				int a = li[i].first, b = li[i].second, aa = li[j].first, bb = li[j].second;
				if ((abs(a - aa) <= 1 && abs(b - bb) <= 1))
				{
					int y = gp(j);
					if (x!=y)
					{
						parent[y] = x;
						num[x] += num[y];
					}
				}
			}
		}
		do
		{
			int arr[2] = { 0,0 }, gam = 0;
			for (size_t i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					gam++;
					continue;
				}
				arr[gam] *= 10;
				arr[gam] += str[i] - '0';
			}
			arr[0]--;
			arr[1]--;
			for (size_t i = 0; i < li.size(); i++)
			{
				if (li[i].first == arr[0] && li[i].second == arr[1])
				{
					cout << num[gp(i)] << endl; 
					break;
				}
			}
		} while (getline(cin,str) && str.size());
	}
}
