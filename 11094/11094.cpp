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
#define mp(x,y) make_pair(x,y) 
#define all(x) x.begin(),x.end()
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<int,int> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
int main()
{
	int n, m, x, y;
	while (cin >> n >> m)
	{
		bool vis[40][40];
		vector<string> tabel(40);
		int answer = 0;
		for (size_t i = 0; i < n; i++)
		{
			cin >> tabel[i];
			for (size_t j = 0; j < m; j++)
			{
				vis[i][j] = 0;
			}
		}
		cin >> x >> y;
		char ac = tabel[x][y];
		pii never = mp(x, y);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				char d = tabel[i][j];
				if (d != ac)continue;
				else if (vis[i][j] == 0)
				{
					bool qul = 1;
					set<pair<int, int>>v;
					queue<pii>q;
					q.push(mp(i, j));
					while (!q.empty())
					{
						pii now = q.front();
						q.pop();
						if (vis[now.first][now.second])continue;
						if (now == never)qul = 0;
						vis[now.first][now.second] = 1;
						v.emplace(now);
						//1
						int a = now.first, b = now.second;
						a++;
						if (a<n && tabel[a][b]==ac)
							q.push(pii(a, b));
						//2
						a = now.first, b = now.second;
						a--;
						if (a>=0 && tabel[a][b] == ac)
							q.push(pii(a, b));

						//3
						a = now.first, b = now.second;
						b++;
						b %= m;
						if (tabel[a][b] == ac)
							q.push(pii(a, b));
						//4
						a = now.first, b = now.second;
						b--;
						if (b == -1)b = m - 1;
						if (tabel[a][b] == ac)
							q.push(pii(a, b));
					}
					if (qul)
					{
						answer = max(answer, (int)v.size());
					}

				}

			}

		}
		cout << answer << endl;
	}

}
//11094
