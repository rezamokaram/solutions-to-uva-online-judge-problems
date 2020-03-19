//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
const ll MAX = 9999999999;
//

const int arr[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
const int zero = 30005;
//
int si(llu t)
{
	int res = 0;
	while (t)
	{
		t /= 10;
		res++;
	}
	return res;
}
void out(ll k)
{
	while (k--)
	{
		cout << " ";
	}
}
/*void pr(int k)
{
	string s;
	s += '0' + (k % 10);
	k /= 10;
	s += '0' + (k % 10);
	k /= 10;
	s += '.';
	s += '0' + (k % 10);
	k /= 10;
	while (k > 0)
	{
		s += '0' + (k % 10); k /= 10;
	}
	string res;
	for (int i = s.size()-1; i >= 0; i--)
		res += s[i];
	cout << res;
}*/
llu stm(string s)
{
	llu res = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			res *= 10;
			res += s[i] - '0';
		}
	}
	return res;
}
int main()
{
	string money;
	while (cin >> money && money!="0.00")
	{
		llu d = stm(money);
		llu p[11][zero];
		for (llu i = 0; i < 11; i++)
		{
			for (llu j = 0; j < d+1; j++)
			{
				llu ans = 0;
				
				if (j>=arr[i])ans += p[i][j - arr[i]];
				if (i)ans += p[i - 1][j];
				if (!j)ans = 1;
				p[i][j] = ans;
			}
		}
		out(6 - money.size());
		cout << money;
		out(17 - (si(p[10][d])>0?si(p[10][d]):1));
		cout << p[10][d] << endl;
	}
}
