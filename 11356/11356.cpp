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
int yd = 365;
bool is_leap_year(int a)
{
	if (a % 100 == 0)
	{
		if (a % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (a % 4 == 0)
	{
		return true;
	}
	return false;
}
char gm[][20] = { "January\0", "February\0", "March\0", "April\0", "May\0", "June\0","July\0", "August\0", "September\0", "October\0", "November\0","December\0" };
int get_month(string a)
{
	for (int i = 0; i < 12; i++)
		if (a==gm[i])
			return i;
	return -1;
}
//
int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
ll nd, day, month, year;
void check()
{
	if (day > months[month])
	{
		day = 1;
		month++;
		if (month >= 12)
		{
			month = 0;
			year++;
		}
	}
}
int main()
{
	int tc, cs = 0;
	cin >> tc;
	string mmonth;
	char sine;

	while (tc--)
	{
		mmonth.clear();
		cin >> year;
		cin >> sine;
		while (cin >> sine && sine != '-')
			mmonth += sine;
		cin >> day >> nd;
		month = get_month(mmonth);
		//
		while (nd > 0)
		{
			//
			if (is_leap_year(year))
			{
				months[1] = 29;
				yd = 366;
			}
			else
			{
				months[1] = 28;
				yd = 365;
			}
			//
			if (nd>367 && day!=1)
			{
				if (month<2)
				{
					if (is_leap_year(year))
					{
						day--;
					}
					year++;
				}
				else
				{
					year++;
					if (is_leap_year(year))
					{
						day--;
					}
				}
				nd -= 365;
			}
			else
			{
				nd--;
				day++;
				check();
			}
		}
		cout << "Case " << ++cs << ": " << year << "-" << gm[month] << "-";
		if (day<10)
			cout << 0;
		cout << day << endl;
	}
}
