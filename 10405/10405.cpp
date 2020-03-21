//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const int MAX = 10000;
//
string a, b;
/*int lcs(int al, int bl)
{
	if (al < 0 || bl < 0)return 0;
	if (a[al]==b[bl])
	{
		return 1 + lcs(al - 1, bl - 1);
	}
	int res1 = lcs(al, bl - 1);
	int res2 = lcs(al - 1, bl);
	return ((res1 > res2) ? res1 : res2);
}*/
//
int arr[1011][1011] = { 0 };
int main()
{

	while (getline(cin,a))
	{
		//cin>>,, is a bug
		getline(cin, b);
		//int al = a.size() - 1, bl = b.size() - 1;

		for (int al=a.size(); al >= 0; al--)
		{
			for (int bl = b.size(); bl >= 0; bl--)
			{
				if (al==a.size() || bl==b.size())
				{
					arr[al][bl] = 0;
					continue;
				}
				if (a[al] == b[bl])
					arr[al][bl] = 1 + arr[al + 1][bl + 1];
				else
					arr[al][bl] = ((arr[al + 1][bl] > arr[al][bl + 1]) ? arr[al + 1][bl] : arr[al][bl + 1]);
			}
		}
		cout << arr[0][0] << endl;
		//cout << lcs(al,bl) << endl;{time_limit};
	}
}
