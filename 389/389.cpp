#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int chartonum(char a)
{
	int ans=0;
	if (a>='0' && a<='9')
	{
		ans = a - '0';
	}
	else if (a>='A' && a<='Z')
	{
		ans = a - 'A' + 10;
	}
	return ans;
}
char numtochar(int a)
{
	char ans = '0';
	if (a<10)
	{
		ans += a;
	}
	else
	{
		ans = 'A' + (a-10);
	}
	return ans;
}
//
ll power(int a, int n)
{
	ll sum = 1;
	for (size_t i = 0; i < n; i++)
	{
		sum *= a;
	}
	return sum;
}
bool is_zero(string a)
{
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i]!='0')
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string number;
	int mbase, nbase;
	while (cin >> number >> mbase >> nbase)
	{
		if (is_zero(number))
		{
			cout << "      0" << endl;
			continue;
		}
		llu sum = 0;
		int pp = 0;
		for (int i = number.length() - 1; i >= 0; i--)
		{
			sum += power(mbase,pp)*chartonum(number[i]);
			pp++;
		}
		//now in ten
		vector<int>list;
		for (size_t i = 0; sum>0 ; i++)
		{
			list.push_back(sum%nbase);
			sum /= nbase;
		}
		if (list.size() > 1)
		{
			while (list[list.size() - 1] == 0)
			{
				list.pop_back();
				if (list.size()<=2)
				{
					break;
				}
			}
		}
		if (list.size()>7)
		{
			cout << "  ERROR" << endl;
		}
		else
		{
			for (size_t i = 0; i < list.size()/2; i++)
			{
				swap(list[i], list[list.size() - 1 - i]);
			}
			for (size_t i = 0; i < 7-list.size(); i++)
			{
				cout << " ";
			}
			for (size_t i = 0; i < list.size(); i++)
			{
				cout << numtochar(list[i]);
			}
			cout << endl;
		}
	}
}
