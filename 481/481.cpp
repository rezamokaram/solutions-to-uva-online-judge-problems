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
const ll MAX = 9999999999;
//
const int zero = 100000;
int el[zero], list[zero],li_id[zero],id[zero];
//
void print(int t)
{
	if (t==-1)
		return;
	print(li_id[t]);
	cout << el[t] << endl;
}
int main()
{
	int max = 0, i = 0,indm=0;
	while (cin >> el[i])
	{
		int pos = lower_bound(list, list + max, el[i]) - list;

		list[pos] = el[i];
		id[pos] = i;
		li_id[i] = pos > 0 ? id[pos - 1] : -1;
		if (pos == max)
		{
			max++;
			indm = i;
		}
		else if (pos==max-1)
		{
			indm = i;
		}
		++i;
	}
	cout << max << endl << "-" << endl;
	print(indm);
}
