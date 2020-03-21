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
using namespace std;
//
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<pair<llu, ll>> vii;
typedef pair<llu, ll> pii;
typedef vector<int> vi;
const ll MAX = 2 * 100000 + 11;
const llu llm = 2 * 100000 * 9999999999 + 1;
typedef pair<ll, pair<int, int>> nod;
//
class number
{
public:
	number();
	number(const number& b)
	{
		sine = b.sine;
		for (size_t i = 0; i < 30; i++)
		{
			u.push_back(b.u[i]);
			l.push_back(b.l[i]);
		}
	}
	void operator =(const number & sec)
	{
		sine = sec.sine;
		for (size_t i = 0; i < 30; i++)
		{
			u[i] = sec.u[i];
			l[i] = sec.l[i];
		}
	}
	~number();
	bool compare(const number& b)
	{
		for (int i = 0; i < 30; i++)
		{
			if (u[i] == b.u[i])continue;
			return (b.u[i] > u[i]);
		}
		for (size_t i = 0; i < 30; i++)
		{
			if (l[i] == b.l[i])continue;
			return (b.l[i] > l[i]);
		}
		return 0;
	}
	bool input()
	{
		string d;
		cin >> d;
		if (d=="0")
		{
			return 0;
		}
		int s = 0, point = d.size();
		if (d[0]=='-')
		{
			sine = 1;
			s = 1;
		}
		for (size_t i = 0; i < d.size(); i++)
		{
			if (d[i] == '.')
			{
				point = i;
				break;
			}
		}
		for (int i = 0; i < 30; i++)
		{
			if (i+1+point<d.size())
			{
				l[i] = (int)(d[point + i + 1] - '0');
			}
			else
			{
				l[i] = 0;
			}
			if (point-1-i>=s)
			{
				u[29 - i] = (int)(d[point - i - 1] - '0');
			}
			else
			{
				u[29 - i] = 0;
			}
		}
		return 1;
	}
	void output()
	{
		string res;
		if(sine)res += '-';
		bool f = 0;
		for (size_t i = 0; i < 30; i++)
		{
			if (u[i] != 0 || f || i==29)
			{
				res += char('0' + u[i]);
				f = 1;
			}
		}
		res += '.';
		for (size_t i = 0; i < 30; i++)
		{
			res += char('0' + l[i]);
		}
		while (res[res.size()-1]=='0')
		{
			res.pop_back();
		}
		if (res[res.size()-1]=='.')
		{
			res.pop_back();
		}
		cout << res << endl;
	}
	void operator +=(number& b)
	{
		if (sine==b.sine)
		{
			int perv = 0;
			for (int i = 29; i >= 0; i--)
			{
				l[i] += b.l[i] + perv;
				perv = l[i] / 10;
				l[i] %= 10;
			}
			//
			for (int i = 29; i >= 0; i--)
			{
				u[i] += b.u[i] + perv;
				perv = u[i] / 10;
				u[i] %= 10;
			}
		}
		else
		{
			if (compare(b))
			{
				number temp(b);
				b = (*this);
				(*this) = temp;
			}
			for (int i = 29; i >= 1; i--)
			{
				if (b.l[i]>l[i])
				{
					l[i] += 10;
					l[i - 1]--;
				}
				l[i] -= b.l[i];
			}
			//
			if (b.l[0] > l[0])
			{
				l[0] += 10;
				u[29]--;
			}
			l[0] -= b.l[0];
			//
			for (int i = 29; i >= 0; i--)
			{
				if (b.u[i] > u[i])
				{
					u[i] += 10;
					u[i - 1]--;
				}
				u[i] -= b.u[i];
			}
		}
	}
	void clcl()
	{
		sine = 0;
		for (size_t i = 0; i < 30; i++)
		{
			u[i] = l[i] = 0;
		}
	}
	void check()
	{
		bool f = 1;
		for (size_t i = 0; i < 30; i++)
			if (u[i] || l[i])
				f = 0;
		if (f)
			sine = 0;
	}
	vector<int>u, l;
	bool sine;
};

number::number()
{
	sine = 0;
	for (size_t i = 0; i < 30; i++)
	{
		u.push_back(0);
		l.push_back(0);
	}

}

number::~number()
{
}
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		number s, p;
		while (p.input())
		{
			s += p;
			p.clcl();
			s.check();
		}
		s.output();
	}
}
