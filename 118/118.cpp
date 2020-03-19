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
typedef vector<pair<ll, ll>> vii;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAX = 100000;
typedef pair<ll, pair<int, int>> nod;
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
string orient = "NESW";
int xsum[4] = { 0,1,0 ,- 1 };
int ysum[4] = { 1,0,-1,0 };
int main()
{
	int a, b;
	cin >> a >> b;
	int x, y, g;
	char sine;
	bool arr[200][200] = { 0 };
	while (cin >> x >> y >> sine)
	{
		for (size_t i = 0; i < 4; i++)
			if (sine == orient[i])
				g = i;
		string s;
		bool f = 0;
		cin >> s;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i]=='F')
			{
				if (x+xsum[g]==a+1 || x+xsum[g]==-1 || y+ysum[g]==b+1 || y+ysum[g]==-1)
				{
					if (!arr[x][y])
					{
						arr[x][y] = f = 1;
						break;
					}
				}
				else
				{
					x += xsum[g];
					y += ysum[g];
				}
			}
			else if (s[i]=='R')
			{
				g++;
				g %= 4;
			}
			else
			{
				g += 3;
				g %= 4;
			}
		}
		cout << x << " " << y << " " << orient[g];
		if (f)
		{
			cout << " LOST";
		}
		cout << endl;
	}
}
