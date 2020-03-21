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
void tout(llu a, llu b)
{
	string aa;
	while (a>0)
	{
		aa += '0' + a % 10;
		a /= 10;
	}
	string bb;
	while (b > 0)
	{
		bb += '0' + b % 10;
		b /= 10;
	}
	bool dd = false;
	if (bb.length()>aa.length())
	{
		dd = true;
	}
	for (size_t i = 1; i <= bb.length(); i++)
	{
		if (!dd)
		{
			char bbb = bb[bb.length() - i];
			char aaa = aa[aa.length() - i];
			if (aaa!=bbb)
			{
				dd = true;
			}
		}
		if (dd)
		{
			cout << bb[bb.length() - i];
		}
	}
	return;
}
//
int main()
{
	int n;
	vector<llu>list;
	int tc = 0;
	while (cin >> n && n)
	{
		if (tc!=0)
		{
			cout << endl<<endl;
		}
		tc++;
		cout << "Case " << tc << ":" << endl;
		for (size_t i = 0; i < n; i++)
		{
			char zero;
			llu number;
			cin >> zero >> number;
			list.push_back(number);
			/*if (zero == '0' && number >= 100 && number <= 2000000000)
			{
				list.push_back(number);
			}*/
		}
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i]==0)
			{
				continue;
			}
			if (i < list.size() - 1)
			{
				if (list[i] != list[i + 1] - 1)
				{
					cout <<"0"<< list[i];
					list[i] = 0;
					if (i != list.size() - 1)
					{
						cout << endl;
					}
				}
				else
				{
					llu firstnumber = list[i];
					llu inc = 0;
					for (size_t j = 0; i + j + 1 < list.size();j++)
					{
						if (list[i + j] == list[i + j + 1] - 1)
						{
							inc++;
							list[i + j] = 0;
						}
						else
						{
							break;
						}
					}
					if (i + inc < list.size())
					{
						list[i + inc] = 0;
					}
					cout << "0"<<firstnumber << "-";
					tout(firstnumber, firstnumber + inc);
					if (i+inc < list.size() - 1)
					{
						cout << endl;
					}
				}
			}
			else
			{
				cout << "0" << list[i];
				list[i] = 0;
				if (i != list.size() - 1)
				{
					cout << endl;
				}
			}
		}
	}
	cout << endl << endl;
}
