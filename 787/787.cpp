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
nod ndc(int a, int b, ll val)
{
	nod t;
	t.first = val;
	t.second.second = b;
	t.second.first = a;
	return t;
}
//
class bignum
{
public:
	bignum(ll mm)
	{
		if (!mm)
		{
			str.push_back(0);
			sine = 0;
			return;
		}
		if (mm<0)
		{
			sine = 1;
			mm*=-1;
		}
		else
		{
			sine = 0;
		}
		while (mm)
		{
			str.push_back(mm % 10);
			mm /= 10;
		}
	}
	bignum(int t, bool a) { str.push_back(t), sine = a; }
	~bignum();
	void mult(ll sec)
	{
		if ((this->sine && sec > 0) || (!this->sine && sec < 0))
			sine = 1;
		else
			sine = 0;
		ll perv = 0;
		for (int i = 0; i < str.size(); i++)
		{
			str[i] *= sec;
			str[i] += perv;
			perv = str[i] / 10;
			str[i] %= 10;
		}
		while (perv)
		{
			str.push_back(perv % 10);
			perv /= 10;
		}
		return;
	}
	int compare(bignum sec)
	{
		/*
		1 = this is bigger
		2 = equal
		3 = sec is bigger
		*/
		if (sine!=sec.sine)
		{
			return (sine ? 3 : 1);
		}
		if (this->str.size()==sec.str.size() && !sine)
		{

			for (int i = this->str.size() - 1; i >= 0; i--)
			{
				if (this->str[i] == sec.str[i])continue;
				else return(this->str[i] > sec.str[i] ? 1 : 3);
			}
		}
		else if(!sine)
			return(this->str.size() > sec.str.size() ? 1 : 3);
		else if (this->str.size() == sec.str.size() && sine)
		{
			for (int i = this->str.size() - 1; i >= 0; i--)
			{
				if (this->str[i] == sec.str[i])continue;
				else return(this->str[i] > sec.str[i] ? 3 : 1);
			}
		}
		else if(sine)
			return(this->str.size() > sec.str.size() ? 3 : 1);
		return 2;
	}
	void out()
	{
		if (sine)cout << "-";
		for (int i = this->str.size() - 1; i >= 0; i--)
			cout << this->str[i];
		cout << endl;
	}
	bool sine;
	vector<ll> str;
};
bignum::~bignum()
{
}
//
int main()
{
	string s;
	while (getline(cin,s) && s != "")
	{
		ofstream out("text");
		out << s;
		out.close();
		ifstream in("text");
		vector<ll>vs;
		ll m;
		bignum mx(0, 0);
		bool kp = 0,kk=0;
		int f, l, n = 0,i=1;
		while (in >> m )//&& m != -999999)
		{
			if (!kp)mx = bignum(m);
			kp = 1;
			if (m == 0 || m == -999999)
			{
				if (vs.size())
				{
					if (!m)mx = (mx.sine ? bignum(0, 0) : mx);
					if (n % 2 == 0)
					{
						bignum now(1, 0);
						for (size_t i = 0; i < vs.size(); i++)
						{
							now.mult(vs[i]);
						}
						int com = mx.compare(now);
						if (com==3)
						{
							mx = now;
						}
					}
					else
					{
						
						if (n==1)
						{
							bignum now(1, 0), nnow(1, 0);
							bool ld = 0, lld = 0;
							for (int i = f+1; i < vs.size(); i++)
							{
								ld = 1;
								now.mult(vs[i]);
							}
							for (int i = l-1; i >= 0; i--)
							{
								lld = 1;
								nnow.mult(vs[i]);
							}
							int com = mx.compare(nnow);
							if (com==3 && lld)
							{
								mx = nnow;
							}
							com = mx.compare(now);
							if (com==3 && ld)
							{
								mx = now;
							}
						}
						else
						{
							bool ld = 0, lld = 0;
							bignum now(1, 0), nnow(1, 0);
							for (int i = f + 1; i < vs.size(); i++)
							{
								ld = 1;
								now.mult(vs[i]);
							}
							for (int i = l - 1; i >= 0; i--)
							{
								lld = 1;
								nnow.mult(vs[i]);
							}
							int com = mx.compare(nnow);
							if (com == 3 && lld)
							{
								mx = nnow;
							}
							com = mx.compare(now);
							if (com == 3 && ld)
							{
								mx = now;
							}
						}
						
					}
				}
				else
				{
					if (!m)mx = (mx.sine ? bignum(0, 0) : mx);
				}
				n = l = f =kk= 0;
				vs.clear();
			}
			else
			{
				if (m<0 && !kk)
				{
					f = vs.size();
					kk = 1;
				}
				if (m < 0)
					l = vs.size(),n++;
				vs.push_back(m);
			}
			if (m == -999999)
				break;
		}
		mx.out();
		in.close();
	}
}
