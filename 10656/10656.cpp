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
vector<int>list, pp, par, inn;
void printt(int d)
{
	
	if(pp[d]!=d)printt(pp[d]);
	cout << par[d] << endl;
}
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		bool f = 0;
		for (size_t i = 0; i < n; i++)
		{
			llu temp;
			cin >> temp;
			if (temp && !f)
				cout << temp, f = 1;
			else if(temp)
				cout << " " << temp;
		}
		if (!f)
			cout << 0;
		cout << endl;
	}
}
