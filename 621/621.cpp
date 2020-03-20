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
bool pr(string str)
{
	if (str=="4")
	{
		return true;
	}
	if (str == "1")
	{
		return true;
	}
	if (str == "78")
	{
		return true;
	}
	return false;
}
//
bool nr(string str)
{
	if (str[str.length()-1]=='5' && str[str.length() - 2] == '3')//&& str.length() > 2)
	{
		return true;
	}
	return false;
}
//
bool ef(string str)
{
	if (str[0] == '9'&& str[str.length() - 1] == '4')
	{
		return true;
	}
	return false;
}
//
int main()
{
	string number;
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		cin >> number;
		bool f = ef(number);
		bool ff = nr(number);
		bool fff = pr(number);
		if (f)
		{
			cout << "*" << endl;
		}
		else if (ff)
		{
			cout << "-" << endl;
		}
		else if (fff)
		{
			cout << "+" << endl;
		}
		else //if (ff)
		{
			cout << "?" << endl;
		}
	}
}
