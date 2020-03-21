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
const int sz = 199999;
void st(int a[],int ind,int tt)
{
	if (a[ind]==0)
	{
		a[ind] = tt;
	}
	else
	{
		a[ind] = min(a[ind], tt);
	}
	return;
}
int mm = 0;
int ann(int ans)
{
	return ans==0?sz:ans;

}
//
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int k, l;
		cin >> k >> l;
		vector<pair<int,int>>p;
		int arr[sz] = { 0 };
		int ans=0;
		for (int i = 0; i < l; i++)
		{
			int li;
			cin >> li;
			for (int j = 0; j < k+1; j++)
			{
				if (!j || arr[j])
				{
					p.push_back(pair<int, int>(j + li, arr[j] + 1));
					//arr[j + li] = arr[j + li]==0 ? arr[j] + 1 : min(arr[j] + 1, arr[j + li]);
					if (j + li >= k)ans = ans == 0 ? li + j : min(ans, li + j);
				}
			}
			for (int j = 0; j < p.size(); j++)
			{
				arr[p[j].first] = arr[p[j].first] == 0 ? p[j].second : min(arr[p[j].first], p[j].second);
			}
			p.clear();
		}
		cout << ans << " " << arr[ans] << endl;
	}
}
