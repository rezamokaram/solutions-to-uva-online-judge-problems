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
bool is_leap_year(int year)
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	return false;
}
//
int month_days(int month, int year)
{
	if (month==1)
	{
		return 31;
	}
	else if (month==2)
	{
		if (is_leap_year(year))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (month==3)
	{
		return 31;
	}
	else if (month == 4)
	{
		return 30;
	}
	else if (month == 5)
	{
		return 31;
	}
	else if (month == 6)
	{
		return 30;
	}
	else if (month == 7)
	{
		return 31;
	}
	else if (month == 8)
	{
		return 31;
	}
	else if (month == 9)
	{
		return 30;
	}
	else if (month == 10)
	{
		return 31;
	}
	else if (month == 11)
	{
		return 30;
	}
	else if (month == 12)
	{
		return 31;
	}
}
//
int d, m, y, bd, bm, by;
//
bool my_comp()
{
	if (by > y)
	{
		return 0;
	}
	if (by == y && bm > m)
	{
		return 0;
	}
	if (by == y && bm == m && bd > d)
	{
		return 0;
	}
	return 1;
}
//
vector<int>yy;
int alldays = 0;
void increse_one_month()
{
	while (my_comp())
	{
		if (bd==d && m==bm && y==by)
		{
			break;
		}
		bd++;
		alldays++;
		if (alldays >= 47946)
		{
			break;
		}
		if (bd>month_days(bm,by))
		{
			bd = 1;
			bm++;

			if (bm>12)
			{
				bm = 1;
				int doby;
				if (is_leap_year(by))
				{
					doby = 366;
				}
				else
				{
					doby = 365;
				}
				yy.push_back(doby);
				by++;
			}
		}
	}
	return;
}
//

int main()
{
	int tc;
	cin >> tc;
	int ntc = 0;
	while (tc--)
	{
		alldays = 0;
		yy.clear();
		//
		ntc++;
		cout << "Case #" << ntc << ": ";
		char sine;
		cin >> d >> sine >> m >> sine >> y >> bd >> sine >> bm >> sine >> by;
		if (!my_comp())
		{
			cout << "Invalid birth date" << endl;
			continue;
		}
		increse_one_month();
		if (alldays >= 47946)
		{
			cout << "Check birth date" << endl;
			continue;
		}
		int ans = 0;
		for (size_t i = 0; i < yy.size(); i++)
		{
			if (yy[i]<=alldays)
			{
				alldays -= yy[i];
				ans++;
			}
		}
		if (ans > 130)
		{
			cout << "Check birth date" << endl;
			continue;
		}
		cout << ans << endl;
	}
}
