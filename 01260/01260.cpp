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
	while (tc--)
	{
		vector<int>list;
		int main = 0;
		int len;
		cin >> len;
		for (size_t i = 0; i < len; i++)
		{
			int temp;
			cin >> temp;
			if (i==0)
			{
				list.push_back(temp);
				continue;
			}
			int count = 0;
			for (size_t j = 0; j < list.size(); j++)
			{
				if (list[j]<=temp)
				{
					main++;
				}
			}
			//
			list.push_back(temp);
		}
		cout << main << endl;
	}
}
