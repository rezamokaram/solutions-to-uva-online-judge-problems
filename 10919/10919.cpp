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
	int c;
	while (cin >> c && c)
	{
		vector<int>list;
		int n;
		cin >> n;
		for (size_t i = 0; i < c; i++)
		{
			int temp;
			cin >> temp;
			list.push_back(temp);
		}
		sort(list.begin(), list.end());
		bool yes = 1;
		for (size_t i = 0; i < n; i++)
		{
			int nc, nm;
			cin >> nc >> nm;
			int has = 0;
			for (size_t j = 0; j < nc; j++)
			{
				int temp;
				cin >> temp;
				if (binary_search(list.begin(), list.end(), temp))
				{
					has++;
				}
			}
			if (has<nm)
			{
				yes = 0;
			}
		}
		if (yes)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
