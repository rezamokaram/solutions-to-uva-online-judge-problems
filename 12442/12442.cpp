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
typedef unsigned long long int ull;
typedef vector<pair<ll, ll>> vii;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
const ll MAX = 2 * 100000 + 11;
const ull llm = 9999999999 + 1;
typedef pair<ll, pair<int, int>> edg;
//
const int six = 100005;
int list[six], pno[six], now[six];
vector<int>perv[six];
bool fix[six], vis[six];
//int gp(int vertex) { return (parent[vertex] == vertex ? vertex : parent[vertex] = gp(parent[vertex])); }
int main()
{
	int tc, cs = 0;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		for (size_t i = 0; i < n+2; i++)
		{
			pno[i] = 0;
			fix[i] = 0;
			vis[i] = 0;
			now[i] = 0;
			list[i] = -1;
			perv[i].clear();
		}
		for (size_t i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			list[a] = b;
			perv[b].push_back(a);
		}
		for (int i = 1; i < n+1; i++)
		{
			if (!fix[i])
			{
				int gam = i, number = 1;
				while (!vis[gam])
				{
					vis[gam] = 1;
					now[gam] = number++;
					gam = list[gam];
				}
				int newnum = number - now[gam],fs=gam;
				do
				{
					fix[gam] = 1;
					gam = list[gam];
					pno[gam] = newnum;
				} while (gam!=fs);
				do
				{
					queue<int>q;
					q.push(gam);
					while (!q.empty())
					{
						int tp;
						tp = q.front();
						q.pop();
						for (size_t z = 0; z < perv[tp].size(); z++)
						{
							int pere = perv[tp][z];
							if (!fix[pere])
							{
								pno[pere] = pno[tp] + 1;
								fix[pere] = 1;
								q.push(pere);
							}
						}
					}
					gam = list[gam];
				} while (gam!=fs);
			}
		}
		//
		int mx = 0, indm = 0;
		for (int i = 1; i <= n; i++)
		{
			int no = pno[i];
			if (mx<no)
			{
				mx = no;
				indm = i;
			}
			/*else if (mx == no && i < indm)
			{
				indm = i;
			}*/
		}
		cout <<"Case " << ++cs << ": " << indm << endl;
		//cout << mx << endl;
	}
}
