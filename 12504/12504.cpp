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
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string key;
		string val;
		char a;
		cin >> a;
		map<string, string>od, nd;
		vector<string>oo, nn;
		while (cin >>a&&a!='}')
		{
			if (a==',')
			{
				continue;
			}
			if (a==':')
			{
				val.clear();
				while (cin >>a && a!=',' && a!='}')
				{
					val += a;
				}
				od[key] = val;
				oo.push_back(key);
				key.clear();
				if (a=='}')
				{
					break;
				}
				continue;
			}
			key += a;
		}
		key.clear();
		cin >> a;
		while (cin >> a && a != '}')
		{
			if (a == ',')
			{
				continue;
			}
			if (a == ':')
			{
				val.clear();
				while (cin >> a && a != ',' && a!='}')
				{
					val += a;
				}
				nd[key] = val;
				nn.push_back(key);
				key.clear();
				if (a == '}')
				{
					break;
				}
				continue;
			}
			key += a;
		}
		//
		vector<string>min, pel, neq;
		for (size_t i = 0; i < oo.size(); i++)
		{
			if (nd[oo[i]]=="")
			{
				min.push_back(oo[i]);
			}
		}
		for (size_t i = 0; i < nn.size(); i++)
		{
			if (od[nn[i]]!="")
			{
				if (od[nn[i]]!=nd[nn[i]])
				{
					neq.push_back(nn[i]);
				}
			}
			else
			{
				pel.push_back(nn[i]);
			}
		}
		sort(neq.begin(), neq.end());
		sort(pel.begin(), pel.end());
		sort(min.begin(), min.end());
		//output
		if (pel.size()==0 && neq.size()==0 && min.size()==0)
		{
			cout << "No changes" << endl << endl;
			continue;
		}
		if (pel.size())
		{
			cout << "+";
			for (size_t i = 0; i < pel.size(); i++)
			{
				if (i)
					cout << ",";
				cout << pel[i];
			}
			cout << endl;
		}
		if (min.size())
		{
			cout << "-";
			for (size_t i = 0; i < min.size(); i++)
			{
				if (i)
					cout << ",";
				cout << min[i];
			}
			cout << endl;
		}
		if (neq.size())
		{
			cout << "*";
			for (size_t i = 0; i < neq.size(); i++)
			{
				if (i)
					cout << ",";
				cout << neq[i];
			}
			cout << endl;
		}
		cout << endl;
	}
}
