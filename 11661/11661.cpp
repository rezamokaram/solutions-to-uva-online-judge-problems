#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int n;
	string fild;
	while (cin >> n >> fild)
	{
		vector<int>r;
		vector<int>d;
		bool z = false;
		for (size_t i = 0; i < fild.length(); i++)
		{
			if (fild[i]=='Z')
			{
				z = true;
				break;
			}
			else if (fild[i]=='R')
			{
				r.push_back(i);
			}
			else if (fild[i]=='D')
			{
				d.push_back(i);
			}
		}
		int min = n;
		if (!z)
		{
			for (size_t i = 0; i < r.size(); i++)
			{
				for (size_t j = 0; j < d.size(); j++)
				{
					int a = abs(r[i] - d[j]);
					if (a<min)
					{
						min = a;
					}
				}
			}
		}
		//
		if (z)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << min << endl;
		}
	}
}
