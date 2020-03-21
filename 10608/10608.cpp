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
int parent[30011], num[30011];
void sset(int n)
{
	for (size_t i = 0; i < n+1; i++)
		parent[i] = i,num[i]=1;
}
int gp(int n)
{
	return(parent[n] == n ? n : parent[n] = gp(parent[n]));
}
int main()
{
	int tc;
	cin >> tc;
	bool f = 0;
	while (tc--)
	{
		int n, m, mx = 1;
		cin >> n >> m;
		sset(n);
		for (size_t i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			int x = gp(a), y = gp(b);
			if (x != y)
			{
				parent[x] = y;
				num[y] += num[x];
				mx = max(mx, num[y]);
			}
		}
		//
		cout << mx << endl;
	}
}
