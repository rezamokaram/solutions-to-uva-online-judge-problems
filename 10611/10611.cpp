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
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
typedef pair<ll, pair<ll, ll>> my;
my nc(ll a, ll b, ll c)
{
	my s;
	s.first = a;
	s.second.first = b;
	s.second.second = c;
	return s;
}
//
int LIS(const vector<int> &d)
{
	vector<int>lis;
	for (size_t i = 0; i < d.size(); i++)
	{
		int pos = upper_bound(lis.begin(), lis.end(), d[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(d[i]);
		else
			lis[pos] = min(lis[pos], d[i]);
	}
	return lis.size();
}
//
llu arr[50005] = { 0 };
//
int main()
{
	int n;
	while (cin >> n)
	{
		for (size_t i = 0; i < n; i++)
			cin >> arr[i];
		int p;
		cin >> p;
		for (size_t i = 0; i < p; i++)
		{
			int t;
			cin >> t;
			int poss = lower_bound(arr, arr + n, t) - arr;
			int pose = upper_bound(arr, arr + n, t) - arr;
			if (arr[poss]==t || poss==0)
			{
				if (poss == 0)
					cout << "X";
				else
					cout << arr[poss - 1];
			}
			else
				cout << arr[poss - 1];
			cout << " ";
			if (arr[pose] == t || pose == n)
			{
				if (pose == n) 
					cout << "X"; 
				else
					cout << arr[pose + 1];
			}
			else
				cout << arr[pose];
			cout << "\n";
		}
	}
}
