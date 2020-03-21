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
typedef pair<int, int> no;
//
const int zero = 1010;
bool ui(nod a, nod b) { return (b.first > a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		int k;
		cin >> k;
		ll sum = 0;
		map<string, int>g;
		int perv = 0;
		int mx = -1;
		for (size_t i = 0; i < k; i++)
		{
			string a;
			int b;
			cin >> a >> b;
			g[a] = b;
			sum += b;
			perv = b;
			mx = max(mx, b);
		}
		if (cs == 90)
		{
			int hlhoglgkf = 1;
		}
		int d;
		cin >> d;
		string due;
		cin >> due;
		cout << "Case " << ++cs << ": ";
		if(!g[due])
		{
			cout << "Do your own homework!" << endl;
		}
		else
		{
			if (g[due]<=d)
			{
				cout << "Yesss" << endl;
			}
			else if (g[due]<=d+5)
			{
				cout << "Late" << endl;
			}
			else
			{
				cout << "Do your own homework!" << endl;
			}
		}
	}
}
