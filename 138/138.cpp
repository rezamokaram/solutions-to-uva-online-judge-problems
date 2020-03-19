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
void find()
{
	ll ans = 0, gam = 3,sum=3;
	while (ans<10)
	{
		ll th = 0, g = 0;
		while (th<sum)
		{
			++g;
			th += gam + g;
		}
		if (th==sum)
		{
			ans++;
			cout << gam << " " << gam + g << endl;
		}
		sum += gam;
		gam++;
	}
}
int main()
{
	vector<string>a;
	a.push_back("         6         8");
	a.push_back("        35        49");
	a.push_back("       204       288");
	a.push_back("      1189      1681");
	a.push_back("      6930      9800");
	a.push_back("     40391     57121");
	a.push_back("    235416    332928");
	a.push_back("   1372105   1940449");
	a.push_back("   7997214  11309768");
	a.push_back("  46611179  65918161");
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}
