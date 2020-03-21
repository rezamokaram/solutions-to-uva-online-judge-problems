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

//
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	int ind = 0;
	while (tc--)
	{
		ind++;
		cout << "Case #" << ind << ":" << endl;
		string temp;
		getline(cin, temp);
		string chars;
		for (size_t i = 0; i < temp.length(); i++)
		{
			if (temp[i]>='a' && temp[i]<='z')
			{
				chars += temp[i];
			}
		}
		//
		int ln = sqrt(chars.length());
		if (ln*ln==chars.length())
		{
			/*
			//making list
			vector<string>list;
			for (size_t i = 0; i < ln; i++)
			{
				string a;
				for (size_t j = 0; j < ln; j++)
				{
					a += chars[(i*ln) + j];
				}
				list.push_back(a);
			}*/
			//process
			bool f = true;
			for (size_t i = 0; i < chars.length(); i++)
			{
				if (chars[i] != chars[chars.length() - i - 1])
				{
					f = false;
					break;
				}
			}
			if (f)
			{
				cout << ln << endl;
			}
			else
			{
				cout << "No magic :(" << endl;
			}
		}
		else
		{
			cout << "No magic :(" << endl;
		}
	}
}
