# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
# include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
vector<int>list;
vector<string>names;
int n,st,pos,fright,fleft;
void lefto(int a)
{
	for (size_t i = 0; i < a; i++)
	{
		cout << "left of ";
	}
}
void righto(int a)
{
	for (size_t i = 0; i < a; i++)
	{
		cout << "right of ";
	}
}
bool rightis()
{
	if (fright == 0)return 0;
	if (fleft == 0 && fright)return 1;
	if (fleft && fright < fleft)return 1;
	return 0;
}
int main()
{
	cin >> n;
	list.push_back(0);
	names.push_back("0");
	for (size_t i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		if (temp != "?")
		{
			list.push_back(i + 1);
			names.push_back(temp);
		}
	}
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> st;
		pos = lower_bound(list.begin(), list.end(), st) - list.begin();
		if (pos == list.size())pos--;
		while (pos >= 1 && list[pos] > st)pos--;
		if (list[pos] == st)
		{
			cout << names[pos] << endl;
		}
		else
		{
			fright = 0;
			fleft = 0;
			if (pos>0)
			{
				fleft = abs(st - list[pos]);
			}
			if (pos<list.size()-1)
			{
				fright = abs(list[pos + 1] - st);
			}
			if (pos == 0)fleft = 0;
			if (pos == list.size() - 1 && st > list[pos])fright = 0;
			if (fleft == fright && fright)
			{
				cout << "middle of " << names[pos] << " and " << names[pos + 1] << endl;
			}
			else if (rightis())
			{
				lefto(fright);
				cout << names[pos + 1] << endl;
			}
			else
			{
				righto(fleft);
				cout << names[pos] << endl;
			}
		}
	}
}
