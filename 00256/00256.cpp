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
const ll p2 = 100;
const ll p4 = p2 * 100;
const ll p6 = p4 * 100;
const ll p8 = p6 * 100;
vector<vector<string>>li(4);
void rev(string & s)
{
	for (int i = 0; i < s.size()/2; i++)
		swap(s[i], s[s.size() - i - 1]);
}
string mmk(ll a,int n)
{
	string res;
	int i = 0;
	while (a && i<n)
	{
		res += '0' + a % 10;
		a /= 10;
		i++;
	}
	while (i++<n)
	{
		res += '0';
	}
	rev(res);
	return res;
}
void make()
{
	li[0].push_back(mmk(0, 2));
	li[1].push_back(mmk(0, 4));
	li[2].push_back(mmk(0, 6));
	li[3].push_back(mmk(0, 8));
	for (ll i = 1; i < p8; i++)
	{
		if (i<p2)
		{
			ll a = i % 10, b = i / 10;
			if ((a+b)*(a+b)==i)
				li[0].push_back(mmk(i, 2));
		}
		if (i<p4)
		{
			if (i == 3025)
			{
				int ppopp = log(3);
			}
			ll ii = i;
			ll a, b;
			a = ii % 10;
			ii /= 10;
			a += 10 * (ii % 10);
			ii /= 10;
			//
			b = ii % 10;
			ii /= 10;
			b += 10 * (ii % 10);
			ii /= 10;
			//
			if ((a + b)*(a + b) == i)
				li[1].push_back(mmk(i, 4));
		}
		if (i<p6)
		{
			ll ii = i;
			ll a, b;
			a = ii % 10;
			ii /= 10;
			a += 10 * (ii % 10);
			ii /= 10;
			a += 100 * (ii % 10);
			ii /= 10;
			//
			b = ii % 10;
			ii /= 10;
			b += 10 * (ii % 10);
			ii /= 10;
			b += 100 * (ii % 10);
			ii /= 10;
			//
			if ((a + b)*(a + b) == i)
				li[2].push_back(mmk(i, 6));

		}
		if (i<p8)
		{
			ll ii = i;
			ll a, b;
			a = ii % 10;
			ii /= 10;
			a += 10 * (ii % 10);
			ii /= 10;
			a += 100 * (ii % 10);
			ii /= 10;
			a += 1000 * (ii % 10);
			ii /= 10;
			//
			b = ii % 10;
			ii /= 10;
			b += 10 * (ii % 10);
			ii /= 10;
			b += 100 * (ii % 10);
			ii /= 10;
			b += 1000 * (ii % 10);
			ii /= 10;
			//
			if ((a + b)*(a + b) == i)
				li[3].push_back(mmk(i, 8));
		}
	}
}
void makes()
{
	li[0].push_back("00");
	li[0].push_back("01");
	li[0].push_back("81");
	//
	li[1].push_back("0000");
	li[1].push_back("0001");
	li[1].push_back("2025");
	li[1].push_back("3025");
	li[1].push_back("9801");
	//
	li[2].push_back("000000");
	li[2].push_back("000001");
	li[2].push_back("088209");
	li[2].push_back("494209");
	li[2].push_back("998001");
	//
	li[3].push_back("00000000");
	li[3].push_back("00000001");
	li[3].push_back("04941729");
	li[3].push_back("07441984");
	li[3].push_back("24502500");
	li[3].push_back("25502500");
	li[3].push_back("52881984");
	li[3].push_back("60481729");
	li[3].push_back("99980001");
	//
}
//
int main()
{
	//make(); to make numbers
	makes();
	int n;
	while (cin >> n)
		for (size_t i = 0; i < li[n / 2 - 1].size(); i++)
			cout << li[n / 2 - 1][i] << endl;
}
