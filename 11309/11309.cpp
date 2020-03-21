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
bool com(int h, int m, int hh, int mm)
{
	if (h!=hh)
		return (h > hh);
	return (m > mm);
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int h, m;
		int hh=0, mm=0;
		char sine;
		cin >> h >> sine >> m;
		
		if (!(com(23, 32, h, m)))
		{
			hh = 0;
			mm = 0;
		}
		else if (com(0, 9, h, m))
		{
			hh = h;
			mm = m + 1;
		}
		else if (com(0, 11, h, m))
		{
			hh = 0;
			mm = 11;
		}
		else if (com(0, 22, h, m))
		{
			hh = 0;
			mm = 22;
		}
		else if (com(0, 33, h, m))
		{
			hh = 0;
			mm = 33;
		}
		else if (com(0, 44, h, m))
		{
			hh = 0;
			mm = 44;
		}
		else if (com(0, 55, h, m))
		{
			hh = 0;
			mm = 55;
		}
		else if (com(9,59,h,m))
		{
			bool f = 0;
			for (size_t i = 1; i < 10; i++)
			{
				for (size_t j = 0; j < 6; j++)
				{
					if (com(i,j*10+i,h,m))
					{
						hh = i;
						mm = j * 10 + i;
						f = 1;
						break;
					}
				}
				if (f)break;
			}
		}
		else
		{
			for (size_t i = 10; i < 24; i++)
			{
				if (i==16)
				{
					i = 20;
				}
				if (com(i, (i % 10) * 10 + i / 10, h, m))
				{
					hh = i;
					mm = (i % 10) * 10 + i / 10;
					break;
				}
			}
		}
		if (hh < 10) { cout << "0"; }
		cout << hh << ":";
		if (mm < 10) { cout << "0"; }
		cout << mm << endl;
	}
}
