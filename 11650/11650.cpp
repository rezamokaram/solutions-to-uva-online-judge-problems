#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int h, m;
		char sine;
		cin >> h >> sine >> m;
		int hh = 11;
		//min
		bool f = false;
		if (m>0 && h==12)
		{
			h = 11;
			f = true;
		}
		else if (m > 0 && h == 11)
		{
			h = 12;
			f = true;
		}
		m = 60 - m;
		if (m == 60)
		{
			m = 0;
			hh++;
		}
		//hour
		if (!f)
		{
			h = hh - h;
			if (h <= 0)
			{
				h = 12;
			}
		}
		/*else if(h==-1)
		{
			h = 12;
		}*/
		//output
		if (h<10)
		{
			cout << 0 << h;
		}
		else
		{
			cout << h;
		}
		cout << sine;
		if (m < 10)
		{
			cout << 0 << m;
		}
		else
		{
			cout << m;
		}
		cout << endl;
	}
}
