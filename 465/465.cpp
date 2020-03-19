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
string al = "abcdefghijklmnopqrstuvwxyz";
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }
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
//
bool mynewCompare(string a, string b)
{
	// true = b is bigger
	// false = a is biger or equal
	if (a.length() == b.length())
	{
		for (size_t i = 0; i < a.length(); i++)
		{
			if (a[i] == b[i])
			{
				continue;
			}
			return (a[i] < b[i]) ? 1 : 0;
		}
	}
	return (a.length() < b.length()) ? 1 : 0;
}
bool cm(string a)
{
	if (a[0]=='-')
	{
		a = myReverse(a);
		a.pop_back();
		a = myReverse(a);
	}
	if (!mynewCompare(a,"2147483648"))
	{
		return 1;
	}
	return 0;
}
//
int main()
{
	char sine;
	string a, b;
	string main;
	while (getline(cin,main))
	{
		a.clear();
		b.clear();
		cout << main << endl;
		bool mf = 1, msine = 1, ms = 1;
		for (size_t i = 0; i < main.length(); i++)
		{
			if (main[i]==' ')
			{
				continue;
			}
			if (main[i]=='+' || main[i] == '/' || main[i] == '-' || main[i] == '*')
			{
				sine = main[i];
				msine = 0;
				mf = 0;
				continue;
			}
			if (mf)
			{
				if (main[i]!=' ')
				{
					a += main[i];
				}
				else
				{
					mf = 0;
				}
			}
			else if (main[i]!=' ' && msine)
			{
				sine = main[i];
				msine = 0;
			}
			else if(main[i] != ' ' && ms)
			{
				b += main[i];
			}
		}
		//cout << a << " " << sine << " " << b << endl;
		a = myReverse(a);
		while (a[a.length()-1]=='0'&& a.length()>1)
		{
			a.pop_back();
		}
		a = myReverse(a);
		//
		b = myReverse(b);
		while (b[b.length() - 1] == '0'&& b.length() > 1)
		{
			b.pop_back();
		}
		b = myReverse(b);
		//
		bool f = 0, s = 0, r = 0;
		//
		if (cm(a) && a[0]!='0')
		{
			f = 1;
		}
		if (cm(b)&&b[0]!='0')
		{
			s = 1;
		}
		//
		if (a[0] == '-' && b[0] == '-' && sine == '*' && (s || f) && a!="0" && b!="0")
		{
			r = 1;
		}
		else if (a[0] != '-' && b[0] != '-' && sine == '+')
		{
			if (s||f)
			{
				r = 1;
			}
			else
			{
				string result = big_sum(a,b);
				if (cm(result))
				{
					r = 1;
				}
			}
		}
		else if (a[0] != '-' && b[0] != '-' && sine == '*'&& a != "0" && b != "0")
		{
			if (s || f)
			{
				r = 1;
			}
			else
			{
				if (a.length()+b.length()>=12)
				{
					r = 1;
				}
				else
				{
					string result = big_mult(a, b);
					if (cm(result))
					{
						r = 1;
					}
				}
			}
		}
		//output
		if (f && a[0]!='-')
		{
			cout << "first number too big" << endl;
		}
		if (s && b[0]!='-')
		{
			cout << "second number too big" << endl;
		}
		if (r)
		{
			cout << "result too big" << endl;
		}
	}
}
