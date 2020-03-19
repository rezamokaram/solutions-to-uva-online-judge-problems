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
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<string>l;
vector<string>n;
vector<bool>s;
//
void bs()
{
	for (size_t i = 0; i < n.size(); i++)
	{
		for (size_t j = 0; j < n.size() - 1 - i; j++)
		{
			if (n[j] > n[j + 1])
			{
				swap(n[j], n[j + 1]);
				swap(l[j], l[j + 1]);
			}
			else if (n[j] == n[j + 1] && l[j] > l[j + 1])
			{
				swap(l[j], l[j + 1]);
			}
		}
	}
}

//
vector<string>nl;
vector<int>ni;
void bbs()
{
	for (size_t i = 0; i < nl.size(); i++)
	{
		for (size_t j = 0; j < nl.size() - 1 - i; j++)
		{
			if (ni[j] > ni[j + 1])
			{
				swap(ni[j], ni[j + 1]);
				swap(nl[j], nl[j + 1]);
			}
		}
	}
}
//
int main()
{
	string str;
	while (cin >> str && str != "END")
	{
		if (str[str.length() - 1] != '"')
		{
			string temp;
			while (cin >> temp)
			{
				str += " " + temp;
				if (str[str.length() - 1] == '"')break;
			}
		}
		//
		l.push_back(str);
		string wr;
		cin >> wr;
		getline(cin, wr);
		n.push_back(wr);
		//
		s.push_back(1);
	}
	bs();
	//
	
	while (cin >> str && str != "END")
	{
		if (str == "SHELVE")
		{
			bbs();
			for (size_t i = 0; i < nl.size(); i++)
			{
				int index = ni[i], second = -1;
				for (int i = index - 1; i >= 0; i--)
				{
					if (s[i])
					{
						second = i;
						break;
					}
				}
				if (index == 0 || second == -1)
				{
					cout << "Put " << l[index] << " first" << endl;
				}
				else
				{
					cout << "Put " << l[index] << " after " << l[second] << endl;
				}
			}
			cout << "END" << endl;
			ni.clear();
			nl.clear();
			continue;
		}
		char a;
		string ll;
		cin >> a;
		getline(cin, ll);
		ll = a + ll;
		if (str == "BORROW")
		{
			for (size_t i = 0; i < l.size(); i++)
			{
				if (l[i] == ll)
				{
					s[i] = 0;
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < l.size(); i++)
			{
				if (l[i] == ll)
				{
					s[i] = 1;
					ni.push_back(i);
					nl.push_back(ll);
					break;
				}
			}
			//
		}
	}
}
