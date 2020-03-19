
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
const int mxsize = 10001;
int arr[mxsize] = { 0 };
int main()
{
	int a, b, c, mr = -1;
	while (cin >> a >> b >> c)
	{
		mr = max(mr, c);
		for (int i = a; i < c; i++)
			arr[i] = max(arr[i], b);
	}
	int perv = arr[1];
	cout << 1 << " " << arr[1];
	for (int i = 1; i <= mr; i++)
	{
		if (arr[i]!=perv)
		{
			cout << " " << i << " " << arr[i];
		}
		perv = arr[i];
	}
	cout << "\n";
}
