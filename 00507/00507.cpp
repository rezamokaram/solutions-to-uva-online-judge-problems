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
ll vs[MAX] = { 0 };
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		n--;
		bool f = 0;
		ll max = 1, s = 0, e = 0, j = 0;
		for (int i = 0; i < n; i++)
		{
			f = 1;
			ll temp;
			cin >> temp;
			vs[i + 1] = temp+vs[i];
			if (!i)max = temp,s=0,e=0;
			while (vs[i+1]-vs[j]<0 && i>=j)
			{
				j++;
				if (vs[i + 1] - vs[j] > max)
				{
					max = vs[i + 1] - vs[j];
					s = j;
					e = i;
				}
				else if (vs[i + 1] - vs[j] == max && i - j > e - s)
				{
					e = i;
					s = j;
				}
			}
			if (vs[i+1]-vs[j]>max)
			{
				max = vs[i + 1] - vs[j];
				s = j;
				e = i;
			}
			else if (vs[i+1]-vs[j]==max && i-j>e-s)
			{
				e = i;
				s = j;
			}
		}
		int i = n-1;
		while (j<=n)
		{
			if (vs[i + 1] - vs[j] > max)
			{
				max = vs[i + 1] - vs[j];
				s = j;
				e = i;
			}
			else if (vs[i + 1] - vs[j] == max && i - j > e - s)
			{
				e = i;
				s = j;
			}
			j++;
		}
		if (f && max>0)
		{
			cout << "The nicest part of route " << ++cs << " is between stops " << s + 1 << " and " << e + 2 << endl;
		}
		else
		{
			cout << "Route "<<++cs<<" has no nice parts" << endl;
		}
	}
}
