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
#define all(x) x.begin(),x.end()
//
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
int p;
int arr[6];
const int mx = 10000;
double cmpt(double x)
{
	double res = arr[0] * exp(-x) + arr[1] * sin(x) + arr[2] * cos(x) + arr[3] * tan(x) + arr[4] * x *x + arr[5];
	return res;
}
int main()
{
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5])
	{
		if (cmpt(1.0) > 1e-9 || arr[0] + arr[2] + arr[5] < 0)
			cout << "No solution\n";
		else
		{
			double high = 1.0, low = 0.0, mid, now;
			for (size_t i = 0; i < 30; i++)
			{
				mid = (low + high) / 2;
				now = cmpt(mid);
				if (now > 0)
					low = mid;
				else
					high = mid;
			}
			cout << fixed << setprecision(4) << low << endl;
		}
	}
}
