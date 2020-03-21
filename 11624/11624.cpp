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
//
const int zero = 1010;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		vector<string>s(a);
		for (int i = 0; i < a; i++)cin >> s[i];
		int fire[zero][zero] = { 0 }, base[zero][zero] = { 0 };
		queue<pair<int, int>>ss, saf;
		for (size_t i = 0; i < a; i++)
		{
			for (size_t j = 0; j < b; j++)
			{
				if (s[i][j] == '#')
					base[i][j] = fire[i][j] = -1;
				else if (s[i][j] == 'J')
					base[i][j] = 1, ss.push(pair<int, int>(i, j));
				else if (s[i][j] == 'F')
					fire[i][j] = 1, saf.push(pair<int, int>(i, j));
				else
					base[i][j] = fire[i][j] = 0;
			}
		}
		while (saf.size())
		{
			pair <int,int> t = saf.front();
			saf.pop();
			int i = t.first, j = t.second;
			if (i && fire[i - 1][j] == 0)
				fire[i - 1][j] = fire[i][j] + 1, saf.push(pair<int, int>(i - 1, j));
			if (i < a - 1 && fire[i + 1][j] == 0)
				fire[i + 1][j] = fire[i][j] + 1, saf.push(pair<int, int>(i + 1, j));
			if (j && fire[i][j - 1] == 0)
				fire[i][j - 1] = fire[i][j] + 1, saf.push(pair<int, int>(i, j - 1));
			if (j < b - 1 && fire[i][j + 1] == 0)
				fire[i][j + 1] = fire[i][j] + 1, saf.push(pair<int, int>(i, j + 1));
		}
		int ans = a * b + 1;
		while (ss.size())
		{
			pair <int, int> t = ss.front();
			ss.pop();
			int i = t.first, j = t.second;
			if (!i || !j || i == a - 1 || j == b - 1)ans = min(ans, base[i][j]);
			//
			if (i && base[i - 1][j] == 0 && (base[i][j] + 1 < fire[i - 1][j] || !fire[i-1][j]))
				base[i - 1][j] = base[i][j] + 1, ss.push(pair<int, int>(i - 1, j));
			if (i < a - 1 && base[i + 1][j] == 0 && (base[i][j] + 1 < fire[i + 1][j] || !fire[i + 1][j]))
				base[i + 1][j] = base[i][j] + 1, ss.push(pair<int, int>(i + 1, j));
			if (j && base[i][j - 1] == 0 && (base[i][j] + 1 < fire[i][j - 1] || !fire[i][j - 1]))
				base[i][j - 1] = base[i][j] + 1, ss.push(pair<int, int>(i, j - 1));
			if (j < b - 1 && base[i][j + 1] == 0 && (base[i][j] + 1 < fire[i][j + 1] || !fire[i][j + 1]))
				base[i][j + 1] = base[i][j] + 1, ss.push(pair<int, int>(i, j + 1));
		}
		if (ans == a * b + 1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
}
