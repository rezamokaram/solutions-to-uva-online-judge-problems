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
string al = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
//
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	bool f = false;
	for (size_t i = 0; i < tc; i++)
	{
		if (f)
		{
			cout << endl;
		}
		f = true;
		vector <string>list;
		vector <string>nlist;
		string str;
		while (getline(cin,str))
		{
			if (str=="")
			{
				break;
			}
			list.push_back(str);
			string ns;
			for (size_t i = 0; i < str.length(); i++)
			{
				if (str[i]==' ')
				{
					continue;
				}
				/*else if (str[i]>='A' && str[i]<='Z')
				{
					ns += str[i] + 32;
				}*/
				else
				{
					ns += str[i];
				}
			}
			sort(ns.begin(), ns.end());
			nlist.push_back(ns);
		}
		//sort(list.begin(),list.end());
		//sort(nlist.begin(), nlist.end());
		vector<string>ans;
		for (size_t j = 0; j < nlist.size() - 1; j++)
		{
			for (size_t z = j + 1; z < nlist.size(); z++)
			{
				if (nlist[j]==nlist[z])
				{
					if (list[j]>list[z])
					{
						ans.push_back(list[z] + " = " + list[j]);
						//cout << list[z] << " = " << list[j] << endl;
					}
					else
					{
						ans.push_back(list[j] + " = " + list[z]);
						//cout << list[j] << " = " << list[z] << endl;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (size_t i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << endl;
		}
	}
}
