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
	int n, b;
	while (cin >> n >> b && n && b)
	{
		vector<int>num(b);
		set<int>sub;
		for (size_t i = 0; i < b; i++)
		{
			cin >> num[i];
			for (size_t j = 0; j <= i && sub.size()!=n+1; j++)
			{
				sub.emplace(abs(num[i] - num[j]));
			}
		}
		if (sub.size()==n+1)
		{
			cout << "Y" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
}
