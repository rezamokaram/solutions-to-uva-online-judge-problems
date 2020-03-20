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
//
const int mx = 10000002;
double arr[mx];
int main()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i < mx; i++)
		arr[i] = arr[i-1]+log10(i);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << (int)arr[n] << endl;
	}
}
