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
string al = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		map<ll, int>ma;
		ll n;
		cin >> n;
		ll nn = n;
		ll max = 0;
		vector<ll>snow(n);
		ll fin = 0, index = 0;
		while (n--)
		{
			cin >> snow[index];
			if (!ma[snow[index]])
			{
				ma[snow[index]] = 1;
			}
			else
			{
				if (max<index-fin)
				{
					max = index - fin;
				}
				ma[snow[index ]]++;
				while (snow[fin]!=snow[index])
				{
					ma[snow[fin]]--;
					fin++;
				}
				ma[snow[fin]]--;
				fin++;
				if (max < index - fin)
				{
					max = index - fin;
				}
			}
			index++;
			if (max < index - fin)
			{
				max = index - fin;
			}
		}
		cout << max << endl;
	}
}
