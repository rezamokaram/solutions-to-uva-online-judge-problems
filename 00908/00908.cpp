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
	int n,cs=0;
	bool f = 0;
	while (cin >> n)
	{
		if (f)cout << endl;
		f = 1;
		pr.clear();
		for (size_t i = 0; i < n+1; i++)
			pr.push_back(i);
		vector<nod>list(n - 1);
		ll sum = 0;
		for (size_t i = 0; i < n-1; i++)
		{
			int s, e;
			ll val;
			cin >> s >> e >> val;
			list[i] = ndc(s, e, val);
			sum += val;
		}
		int A;
		cin >> A;
		for (size_t i = 0; i < A; i++)
		{
			int s, e;
			ll val;
			cin >> s >> e >> val;
			list.push_back(ndc(s, e, val));
		}
		cin >> A;
		for (size_t i = 0; i < A; i++)
		{
			int s, e;
			ll val;
			cin >> s >> e >> val;
			list.push_back(ndc(s, e, val));
		}
		sort(list.begin(), list.end(), ui);
		ll mst = 0;
		for (size_t i = 0; i < list.size(); i++)
		{
			if (getp(list[i].second.first)!=getp(list[i].second.second))
			{
				mst += list[i].first;
				pr[getp(list[i].second.first)] = getp(list[i].second.second);
			}
		}
		cout << sum << endl << mst << endl;
	}
}
