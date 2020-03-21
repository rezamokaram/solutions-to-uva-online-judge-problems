#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
map<string, string>ma;
string al = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	string str;
	while (getline(cin,str) && str!="")
	{
		string a, b;
		bool f = 1;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i]==' ')
			{
				f = 0;
			}
			else if (f)
			{
				a += str[i];
			}
			else
			{
				b += str[i];
			}
		}
		ma[b] = a;
	}
	while (cin >> str)
	{
		if (ma[str]!="")
		{
			cout << ma[str] << endl;
		}
		else
		{
			cout << "eh" << endl;
		}
	}
}
