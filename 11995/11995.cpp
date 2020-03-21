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
	int n;
	while (cin >> n)
	{
		vector<int>ss;
		vector<int>qq;
		priority_queue<int>pp;
		bool s = 1, q = 1, p = 1;
		int first = 0;
		for (size_t i = 0; i < n; i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			if (t1==1)
			{
				ss.push_back(t2);
				qq.push_back(t2);
				pp.push(t2);
			}
			else
			{
				if (ss.size() && ss[ss.size()-1]==t2)
				{
					ss.pop_back();
				}
				else
				{
					s = 0;
				}
				if ((qq.size() - first) && qq[first]==t2)
				{
					first++;
				}
				else
				{
					q = 0;
				}
				if (pp.size() && pp.top() == t2)
				{
					pp.pop();
				}
				else
				{
					p = 0;
				}
			}
		}
		int ans = 0;
		if (p)ans++;
		if (q)ans++;
		if (s)ans++;
		if (ans==0)
		{
			cout << "impossible" << endl;
		}
		else if (ans>=2)
		{
			cout << "not sure" << endl;
		}
		else if (q)
		{
			cout << "queue" << endl;
		}
		else if (p)
		{
			cout << "priority queue" << endl;
		}
		else
		{
			cout << "stack" << endl;
		}
	}
}
