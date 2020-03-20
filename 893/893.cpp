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
//
int main()
{
	ll nd, day, month, year;
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> nd >> day >> month >> year)
	{
		if (nd == 0 && day == 0 && month == 0 && year == 0)
		{
			break;
		}
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
			if (nd >= yd)
			{
				nd -= yd;
				year++;
				if (month > 2 && is_leap_year(year - 1) == true)
				{
					months[1] = 29;
					yd = 366;
					day++;
					//nd--;
					if (day > months[month - 1])
					{
						day -= months[month - 1];
						month++;
					}
					if (month > 12)
					{
						year++;
						month -= 12;
					}
				}
				else if (month > 2 && is_leap_year(year) == true)
				{
					months[1] = 29;
					yd = 366;
					day--;
					//nd++;
					if (day == 0)
					{
						month--;
						if (month == 0)
						{
							year--;
							month = 12;
						}
						day = months[month - 1];
						
					}
					
				}
				else if (month == 2 && day == 29 && is_leap_year(year) == false)
				{
					months[1] = 28;
					yd = 365;
					month++;
					day = 1;
				}
			}
			else if (nd > months[month - 1])
			{
				nd -= months[month - 1];
				month++;
				if (month > 12)
				{
					year++;
					month -= 12;
				}
			}
			else
			{
				day++;
				nd--;
				if (day > months[month - 1])
				{
					day -= months[month - 1];
					month++;
				}
				if (month > 12)
				{
					year++;
					month -= 12;
				}
			}
			//
		}
		cout << day << " " << month << " " << year << endl;
	}
}
