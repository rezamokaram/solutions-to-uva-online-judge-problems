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
bool myCompare(string a, string b)
{
	// true = b is bigger or equal
	// false = a is biger
	if (a.length() == b.length())
	{
		for (size_t i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i])
			{
				continue;
			}
			return (a[i] < b[i]);
		}
	}
	return (a.length() <= b.length());
}
string myAddzero(string str, int number_of_zero)
{
	for (size_t i = 0; i < number_of_zero; i++)
	{
		str += '0';
	}
	return str;
}
string myReverse(string str)
{
	string nstr;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		nstr += str[i];
	}
	return nstr;
}
string myItostr(llu number)
{
	string nstr;
	while (number > 0)
	{
		nstr += number % 10 + '0';
		number /= 10;
	}
	nstr = myReverse(nstr);
	return nstr;
}
string big_sum(string a, string b)
{
	if (a.length() < b.length())
	{
		swap(a, b);
	}
	a = myReverse(a);
	b = myReverse(b);
	int sum = 0;
	string nstr;
	for (size_t i = 0; i < a.length(); i++)
	{
		sum += a[i] - '0';
		if (i < b.length())
		{
			sum += b[i] - '0';
		}
		nstr += (sum % 10) + '0';
		sum /= 10;
	}
	while (sum > 0)
	{
		nstr += (sum % 10) + '0';
		sum /= 10;
	}
	nstr = myReverse(nstr);
	if (nstr[0] == '0')
	{
		return "0";
	}
	return nstr;
}
string big_mult(string a, string b)
{
	if (a.length() < b.length())
	{
		swap(a, b);
	}
	string main = "0";
	for (size_t i = 0; i < b.length(); i++)
	{
		string this_sum = myAddzero(a, b.length() - 1 - i);
		int n = b[i] - '0';
		for (size_t j = 0; j < n; j++)
		{
			main = big_sum(main, this_sum);
		}
	}
	if (main[0] == '0')
	{
		return "0";
	}
	return main;
}
string big_power(string a, llu b)
{
	if (b == 0)
	{
		return "1";
	}
	string main = "1";
	for (size_t i = 0; i < b; i++)
	{
		main = big_mult(main, a);
	}
	if (main[0] == '0')
	{
		return "0";
	}
	return main;
}
string big_minus(string a, string b)
{
	//return ( a - b ) ;
	//not true for under 0
	a = myReverse(a);
	b = myReverse(b);
	for (size_t i = 0; i < b.length(); i++)
	{
		if (a[i] >= b[i])
		{
			a[i] -= (b[i] - '0');
		}
		else
		{
			a[i] += 10 - (b[i] - '0');
			bool f = false;
			for (size_t j = 1; !f && i + j < a.length(); j++)
			{
				if (a[i + j] == '0')
				{
					a[i + j] += 9;
					continue;
				}
				else if (a[i + j] >= '1')
				{
					a[i + j]--;
					f = true;
					break;
				}
			}
			if (!f)
			{
				return "eroor : B is biger than A";
			}
		}
	}
	string nstr = a;
	//keep zeros
	while (nstr[nstr.length() - 1] == '0' && nstr.length() > 1)
	{
		nstr.pop_back();
	}
	nstr = myReverse(nstr);
	return nstr;
}
string big_divid(string a, string b)
{
	string counter = "0";
	while (myCompare(b, a))
	{
		a = big_minus(a, b);
		counter = big_sum(counter, "1");
	}
	return counter;
}
//
string my_string_crop(string str, int start, int end)
{
	string nstr;
	for (size_t i = start; i < end; i++)
	{
		nstr += str[i];
	}
	return nstr;
}
string decimal_to_binary(ll number)
{
	// return a reverse string
	string nstr;
	while (number > 0)
	{
		nstr += (number % 2) + '0';
		number /= 2;
	}
	return nstr;
}
string build_my_ans(string a, string b)
{
	if (a.length()<b.length())
	{
		swap(a, b);
	}
	string nstr;
	for (size_t i = 0; i < a.length(); i++)
	{
		char temp = a[i];
		if (i<b.length())
		{
			if (b[i]=='1' && temp=='1')
			{
				temp = '0';
			}
			else if (temp=='0' && b[i]=='1')
			{
				temp = '1';
			}
		}
		nstr += temp;
	}
	nstr = myReverse(nstr);
	return nstr;
}
ll binary_to_decimal(string str)
{
	ll ans = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		int temp = str[i] - '0';
		ans += pow(2, str.length() - i - 1)*temp;
	}
	return ans;
}
//
int main()
{
	ll a,b;
	while (cin >> a >> b)
	{
		string a1 = decimal_to_binary(a);
		string b1 = decimal_to_binary(b);
		string ans = build_my_ans(a1, b1);
		ll rans = binary_to_decimal(ans);
		cout << rans << endl;
	}
}
