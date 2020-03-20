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
//
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (size_t i = 0; i < n; i++)
	{
		
		string a;
		getline(cin,a);
		if (i==3214)
		{
			//cout << "me" << endl;
		}
		if (a=="")
		{
			cout << "Yes" << endl;
			continue;
		}
		bool f = true;
		for (size_t j = 0; j < a.length(); j++)
		{
			if (a[j]==')' /*|| a[j]==']'*/)
			{
				int d = j;
				bool ff = false;
				int v = 0;
				for ( d = j-1; d >= 0; d--)
				{
					v++;
					if (a[d]=='(')
					{
						a[d] = ',';
						a[j] = ',';
						ff = true;
						if (v%2==0)
						{
							ff = false;
						}
						break;
					}
				}
				if (!ff)
				{
					f = false;
					break;
				}
			}
			else if (a[j] == ']')
			{
				int d = j;
				bool ff = false;
				int v = 0;
				for (d = j-1; d >= 0; d--)
				{
					v++;
					if (a[d] == '[')
					{
						a[d] = ',';
						a[j] = ',';
						ff = true;
						if (v % 2 == 0)
						{
							ff = false;
						}
						break;
					}
				}
				if (!ff)
				{
					f = false;
					break;
				}
			}
		}
		for (size_t j = 0; j < a.length() && f; j++)
		{
			if (a[j]!=',')
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}
