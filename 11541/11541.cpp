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
int stoint(int start, string str)
{
	int len = 0;
	int s = 0;
	for (size_t i = start+1; i < str.length(); i++)
	{
		if (str[i]>='0'&&str[i]<='9')
		{
			if (len==0)
			{
				s = i;
			}
			len++;
		}
		else if (len!=0)
		{
			break;
		}
	}
	int in = 0;
	int mg = 0;
	int p = len - 1;
	for (size_t i = s; i < s+len; i++)
	{
		in = (str[i] - '0');
		if (p>0)
		{
			in *= pow(10, p);
		}
		
		mg += in;
		p--;
	}
	return mg;
}
//
int main()
{
	int tc;
	cin >> tc;
	for (size_t t = 1; t <= tc; t++)
	{
		cout << "Case " << t << ": ";
		string str;
		cin >> str;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i]>='0'&& str[i]<='9')
			{
				continue;
			}
			int len = stoint(i, str);
			for (size_t j = 0; j < len; j++)
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
}
