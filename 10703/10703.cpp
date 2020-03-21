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
typedef vector<pair<ll, ll>> vii;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
//
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k && n && m)
	{
		int ans = n * m;
		bool arr[502][502] = { 0 };
		while (k--)
		{
			int a, b, x, y;
			cin >> a >> b >> x >> y;
			a--; b--; x--; y--;
			for (size_t i = min(a,x); i <= max(a,x); i++)
				for (size_t j = min(b,y); j <= max(b,y); j++)
					if (!arr[i][j])ans--, arr[i][j] = 1;
		}
		if (ans <= 0)cout << "There is no empty spots." << endl;
		else if (ans == 1)cout << "There is one empty spot." << endl;
		else cout << "There are "<<ans<<" empty spots." << endl;
	}
}
