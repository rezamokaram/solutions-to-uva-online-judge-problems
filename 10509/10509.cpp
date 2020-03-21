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
int main()
{
	double number;
	while (cin >> number && number != 0.0)
	{
		double cb = cbrt(number);
		ll a = cb;
		cb = a;
		double point = (number - cb * cb*cb) / 3.0 / cb / cb;
		cout << fixed << setprecision(4) <<  cb + point << endl;
	}
}
