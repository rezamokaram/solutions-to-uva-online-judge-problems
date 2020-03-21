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
typedef pair<int, int> no;
//
const int zero = 1010;
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
int main()
{
	int a, b;
	while (cin >> a >> b && a)
	{
		vector<bool>done(a, 0);
		vector <vector<int>>li(a);
		//parent
		for (size_t i = 0; i < b; i++)
		{
			int t, tt;
			cin >> t >> tt;
			t--;
			tt--;
			li[tt].push_back(t);
		}
		vector<int>ans;
		while (ans.size()<a)
		{
			for (size_t i = 0; i < a; i++)
			{
				if (done[i])continue;
				if (li[i].size() == 0)
				{
					done[i] = 1;
					ans.push_back(i + 1);
					continue;
				}
				while (li[i].size() && done[li[i][li[i].size()-1]])
					li[i].pop_back();
				if (li[i].size() == 0)
				{
					done[i] = 1;
					ans.push_back(i + 1);
					continue;
				}
			}
		}
		for (size_t i = 0; i < ans.size(); i++)
		{
			if (i)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}
