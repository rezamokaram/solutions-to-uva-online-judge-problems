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
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string temp;
		getline(cin, temp);
		string str;
		for (size_t i = 0; i < temp.length(); i++)
		{
			if (temp[i]!=' ')
			{
				str += temp[i];
			}
		}
		int rf = 0, rm = 0, lm = 0, lf = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (i%2==0)
			{
				if (str[i] == 'M')
				{
					lm++;
				}
				else if (str[i] == 'F')
				{
					lf++;
				}
			}
			else
			{
				if (str[i] == 'M')
				{
					rm++;
				}
				else if (str[i] == 'F')
				{
					rf++;
				}
			}
		}
		if (lf==rm && rf==lm && lm+rm>1 && rf+lf>1)
		{
			cout << "LOOP" << endl;
		}
		else
		{
			cout << "NO LOOP" << endl;
		}
	}
}
