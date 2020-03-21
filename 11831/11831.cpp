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
typedef pair<ll, ll> no;
no nc(ll a, ll b) { return pair<ll, ll>(a, b); }
//
bool ui(no a, no b) { return (b.first < a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
//
int vazD(int a) { return (a + 1) % 4; }
int vazE(int a) { return (!a ? 3 : a - 1); }
int main()
{
	int a, b, n;
	while (cin >> a >> b >> n && a && b)
	{
		int ans = 0;
		vector<string>s(a);
		vector<vector<bool>>f(a);
		int x = 0, y = 0, vaz = 0;
		for (size_t i = 0; i < a; i++)
		{
			cin >> s[i];
			for (size_t j = 0; j < s[i].size(); j++)
			{
				f[i].push_back(0);
				if (s[i][j] >= 'A' && s[i][j] <= 'Z')
				{
					x = i;
					y = j;
					if (s[i][j] == 'O')vaz = 0;
					else if (s[i][j] == 'N')vaz = 1;
					else if (s[i][j] == 'L')vaz = 2;
					else vaz = 3;
				}
			}

		}
		for (size_t i = 0; i < n; i++)
		{
			char v;
			cin >> v;
			if (v == 'F') 
			{
				if (vaz == 0) 
				{
					if (y && s[x][y - 1] != '#')
						y--;
				}
				else if (vaz == 1) 
				{
					if (x && s[x - 1][y] != '#')
						x--;
				}
				else if (vaz == 2) 
				{
					if (y < b - 1 && s[x][y + 1] != '#')
						y++;
				}
				else 
				{
					if (x < a - 1 && s[x + 1][y] != '#')
						x++;
				}
			}
			else if (v == 'D')
			{
				vaz = vazD(vaz);
			}
			else
			{
				vaz = vazE(vaz);
			}
			if (!f[x][y])
			{
				f[x][y] = 1;
				if (s[x][y] == '*')ans++;
			}
		}
		cout << ans << endl;
	}
}
