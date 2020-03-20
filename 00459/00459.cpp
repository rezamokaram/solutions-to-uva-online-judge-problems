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
int parent[26] = { 0 };
void sset()
{
	for (size_t i = 0; i < 26; i++)
		parent[i] = i;
}
int gp(int n)
{
	return(parent[n] == n ? n : parent[n] = gp(parent[n]));
}
int main()
{
	int tc;
	cin >> tc;
	bool f = 0;
	while (tc--)
	{
		if (f)
			cout << endl;
		f = 1;
		sset();
		char nu;
		cin >> nu;
		cin.ignore();
		int n = nu - 'A';
		string p;
		while (getline(cin, p) && p.size())
		{
			char aa, bb;
			aa = p[0];
			bb = p[1];
			int a = aa - 'A', b = bb - 'A';
			int x = gp(a), y = gp(b);
			parent[x] = y;
		}
		set<int>ans;
		for (size_t i = 0; i <= n; i++)
			ans.emplace(gp(parent[i]));
		cout << ans.size() << endl;
	}
}
