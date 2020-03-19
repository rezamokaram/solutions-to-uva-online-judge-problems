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
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		string temp;
		bool ff = 0;
		for (size_t i = 0; i < str.length() / 2; i++)
		{
			temp += str[i];
			if (str.length()%temp.length()!=0)
			{
				continue;
			}
			bool f = true;
			for (size_t j = 0; j < str.length(); j++)
			{
				if (str[j]!=temp[j%temp.length()])
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				ff = true;
				break;
			}
		}
		if (ff)
		{
			cout << temp.length() << endl;
		}
		else
		{
			cout << str.length() << endl;
		}
		if (n)
		{
			cout << endl;
		}
	}
}
