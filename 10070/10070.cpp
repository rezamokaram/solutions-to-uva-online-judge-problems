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
bool mod4(string str)
{
	int temp = (str[str.length() - 2] * 10) + (str[str.length() - 1]);
	if (temp%4==0)
	{
		return true;
	}
	return false;
}
//
bool mod100(string str)
{
	if (str[str.length()-2]=='0' && str[str.length() - 1] == '0')
	{
		return true;
	}
	return false;
}
//
bool mod400(string str)
{
	int temp = (str[str.length() - 4] * 10) + (str[str.length() - 3]);
	if (str[str.length() - 2] == '0' && str[str.length() - 1] == '0' && temp%4==0)
	{
		return true;
	}
	return false;
}
//
bool mod3(string str)
{
	llu sum = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		sum += str[i] - '0';
	}
	if (sum%3==0)
	{
		return true;
	}
	return false;
}
//
bool mod5(string str)
{
	if (str[str.length()-1]=='5' || str[str.length() - 1] == '0')
	{
		return true;
	}
	return false;
}
//
bool mod11(string str)
{
	ll sum1 = 0;
	ll sum2 = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i%2==0)
		{
			sum2 += str[i] - '0';
		}
		else
		{
			sum1 += str[i] - '0';
		}
	}
	if (sum1 > sum2)
	{
		sum1 -= sum2;
	}
	else
	{
		sum1 = sum2 - sum1;
	}
	if (sum1 % 11 == 0)
	{
		return true;
	}
	return false;
}
//
bool is_leap_year(string year)
{
	if (mod400(year))
	{
		return true;
	}
	if (mod4(year) && !mod100(year))
	{
		return true;
	}
	return false;
}
//

int main()
{
	string year;
	bool ff = false;
	while (cin >> year)
	{
		if (ff)
		{
			cout << endl;
		}
		ff = true;
		bool f = false;
		bool fl = false;
		if (is_leap_year(year))
		{
			cout << "This is leap year." << endl;
			f = true;
			fl = true;
		}
		if (mod5(year) && mod3(year))
		{
			cout << "This is huluculu festival year." << endl;
			f = true;
		}
		if (mod5(year) && mod11(year) && fl)
		{
			cout << "This is bulukulu festival year." << endl;
			f = true;
		}
		if(!f)
		{
			cout << "This is an ordinary year." << endl;
		}
		//cout << endl;
	}
}
