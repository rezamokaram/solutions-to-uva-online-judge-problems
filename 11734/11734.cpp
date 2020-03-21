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
const int zero = 1010;
bool ui(no a, no b) { return (b.first < a.first); }
vector<int>pr;
int getp(int n) { return pr[n] == n ? n : getp(pr[n]); }
llu gcd(llu a, llu b) { return(b == 0 ? a : gcd(b, a%b)); }
llu lcm(llu a, llu b) { return a / gcd(a, b)*b; }
void out(ll n, no a)
{
	cout << "1/" << n << " = 1/" << a.first << " + 1/" << a.second << endl;
}
int main()
{
	int n, cs = 0;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		cout << "Case " << ++cs << ": ";
		string a, b;
		getline(cin, a);
		getline(cin, b);
		bool f = 0;
		for (size_t i = 0; i < a.size(); i++)
			if (a[i] == ' ') { f = 1; break; }
		bool wr = 0;
		string g,p;
		ofstream out("text.txt");
		out << a;
		out.close();
		ifstream in("text.txt");
		while (in >> p)g += p;
		in.close();
		if (g!=b)
		{
			wr = 1;
		}
		if (wr)
			cout << "Wrong Answer" << endl;
		else if (f)
			cout << "Output Format Error" << endl;
		else if (a == b)
			cout << "Yes" << endl;
		else
			cout << "Wrong Answer" << endl;

	}
}
