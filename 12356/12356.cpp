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
	int s, g;
	while (cin >> s >> g && s && g)
	{
		vector<int>right,left;
		right.push_back(0);
		left.push_back(0);
		for (size_t i = 0; i < s; i++)
		{
			right.push_back(i + 2);
			left.push_back(i);
		}
		right[s] = -1;
		left[1] = -1;
		for (size_t i = 0; i < g; i++)
		{
			int start, end;
			cin >> start >> end;
			if (right[end]>=0 && right[end]<left.size())
			{
				left[right[end]] = left[start];
			}
			if (left[start]>=0 && left[start]<right.size())
			{
				right[left[start]] = right[end];
			}
			if (left[start]!=-1)
			{
				cout << left[start];
			}
			else
			{
				cout << "*";
			}
			cout << " ";
			if (right[end]!=-1)
			{
				cout << right[end];
			}
			else
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << "-" << endl;
	}
}
