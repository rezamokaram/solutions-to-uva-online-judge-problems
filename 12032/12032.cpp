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
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<ll>li(n);
		ll perv = 0, ans = 0, mx = 0, indm;
		for (int i = 0; i < n; i++)
		{
			ll now;
			cin >> now;
			li[i] = now - perv;
			if (li[i] > ans)
			{
				ans = li[i];
				indm = i + 1;
			}
			perv = now;
		}
		mx = ans-1;// -(indm <= 1 ? 0 : 1);
		for (int i = indm; i < n; i++)
		{
			if (li[i] == mx)
				mx--;
			else if(li[i]>mx)
			{
				ans++;
				break;
			}
		}
		cout << "Case " << ++cs << ": " << ans << endl;
	}
}
