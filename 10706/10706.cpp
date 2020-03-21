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
const int mmx = 100000;
ll arr[mmx];
int tenpo = 10, nn = 1;
int len(ll a)
{
	if (a == tenpo)
	{
		tenpo *= 10;
		return ++nn;
	}
	return nn;
}
ll cm(ll a)
{
	ll res = a;
	llu ten = 10;
	while (a >= ten)
	{
		res += a - (ten - 1);
		ten *= 10;
	}
	return res;
}
void sst()
{
	arr[0] = 0;
	for (ll i = 1; i < mmx; i++)
	{
		arr[i] = cm(i) + arr[i - 1];
	}
}
//
string pp(ll a)
{
	string res;
	while (a)
	{
		res += char('0' + a % 10);
		a /= 10;
	}
	for (size_t i = 0; i < res.size() / 2; i++)
		swap(res[i], res[res.size() - i - 1]);
	return res;
}
//
//
int main()
{
	sst();
	int tc;
	//cout << arr[9] << endl << arr[99] << endl << arr[999] << endl << arr[9999] << arr[99999] << arr[99999] << endl;
	//cout << "kir e khar \n";
	cin >> tc;
	while (tc--)
	{
		tenpo = 10;
		nn = 1;
		ll n;
		cin >> n;
		int pos = lower_bound(arr, arr + mmx, n) - arr;
		if (n==arr[pos])
		{
			cout << pos % 10 << endl;
			continue;
		}
		n -= arr[pos - 1];
		int p = 0;
		char ans = '.';
		int rah = 0;
		for (ll i = 1; rah < n; i++)
		{
			string d = pp(i);
			p = d.size();// len(i + 1);
			if (n - rah <= p)
			{
				for (size_t j = 0; j < d.size(); j++)
				{
					if (rah + j + 1 == n)
					{
						ans = d[j];
						break;
					}
				}
				break;
			}
			rah += p;
		}
		cout << ans << endl;
	}
}
