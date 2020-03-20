#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int len(llu x)
{
	int ans = 0;
	while (x>0)
	{
		x /= 10;
		ans++;
	}
	return ans;
}
llu i, sec;
bool is_ok()
{
	if (i>99999 || sec>99999)
	{
		return 0;
	}
	int x = i;
	int y = sec;
	int dig[10] = { 0 };
	if (x<10000 || y<10000)
	{
		dig[0]++;
	}
	while (x > 0)
	{
		dig[x % 10]++;
		x /= 10;
	}
	while (y > 0)
	{
		dig[y % 10]++;
		y /= 10;
	}
	for (size_t i = 0; i < 10; i++)
	{
		if (dig[i]!=1)
		{
			return 0;
		}
	}
	return 1;
}
//
void out(llu x)
{
	if (x<10000)
	{
		cout << 0;
	}
	cout << x;
}
//
int main()
{
	int m;
	bool first = 1;
	while (cin >> m && m)
	{
		if (!first)
		{
			cout << endl;
		}
		first = 0;
		bool f = 0;
		for (i = 1234; i < 50000; i++)
		{
			sec = i * m;
			if (is_ok())
			{
				f = 1;
				out(sec);
				cout << " / ";
				out(i);
				cout << " = " << m << endl;
			}
		}
		if (!f)
		{
			cout << "There are no solutions for " << m << "." << endl;
		}
	}
}
