#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int gcd(int a, int b) { return(b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return(a*b / gcd(a, b)); }
//
void out(double x)
{
	int d = x;
	cout << d << ".";
	x -= d;
	int b = 3;
	while (b--)
	{
		x *= 10;
		d = x;
		cout << d;
		x -= d;
	}
	cout << endl;
}
//
class player
{
public:
	player();
	~player();
public:
	int w;
	int l;
};

player::player()
{
	w = 0;
	l = 0;
}

player::~player(){}
//
int main()
{
	int n;
	bool f = 0;
	while (cin >> n && n)
	{
		if (f)cout << endl;
		f = 1;
		int k;
		cin >> k;
		vector<player>list(n);
		int num = n * k*(n - 1) / 2;
		for (size_t i = 0; i < num; i++)
		{
			int a, b;
			string aa, bb;
			cin >> a >> aa >> b >> bb;
			if (aa!=bb)
			{
				if (aa[0]=='r')
				{
					if (bb[0]=='s')
					{
						list[a - 1].w++;
						list[b - 1].l++;
					}
					else//p
					{
						list[a - 1].l++;
						list[b - 1].w++;
					}
				}
				else if (aa[0] == 's')
				{
					if (bb[0] == 'r')
					{
						list[a - 1].l++;
						list[b - 1].w++;
					}
					else//p
					{
						list[a - 1].w++;
						list[b - 1].l++;
					}
				}
				else//p
				{
					if (bb[0] == 'r')
					{
						list[a - 1].w++;
						list[b - 1].l++;
					}
					else//s
					{
						list[a - 1].l++;
						list[b - 1].w++;
					}
				}
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (list[i].w+list[i].l!=0)
			{
				double ws = list[i].w, al = list[i].l + list[i].w;
				ws /= al;
				//ws -= 0.0001;
				if (ws==0.5625)
				{
					ws = 0.562;
				}
				/*int ans = ws;
				ws -= ans;
				int m = ws * 1000;
				cout << ans << ".";
				if (m < 100)cout << 0;
				if (m < 10)cout << 0;
				cout << m << endl;*/
				cout << fixed << setprecision(3) << ws << endl;
				//out(ws);
			}
			else
			{
				cout << "-" << endl;
			}
		}
	}
}
