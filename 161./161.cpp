#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
bool green(const vector<int>& list, const vector<int>& dlist, int time)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (time % dlist[i] >= list[i] - 5)
		{
			return false;
		}
	}
	return true;
}
//
int main()
{
	while (true)
	{
		vector<int>list;
		vector<int>dlist;
		int temp;
		int time;
		bool f = true;
		while (cin >> temp && temp)
		{
			if (f)
			{
				time = temp;
			}
			list.push_back(temp);
			dlist.push_back(temp * 2);
			if (temp<time)
			{
				time = temp;
			}
			f = false;
		}
		if (list.size()==0)
		{
			cin >> temp >> temp;
			break;
		}
		bool dd;
		while (!(dd=green(list,dlist,time)) && time<5*3600)
		{
			time++;
		}
		if (dd)
		{
			int min = time % 3600;
			int hour = time / 3600;
			int sec = min % 60;
			min /= 60;
			cout << "0" << hour << ":";
			if (min<10)
			{
				cout << "0";
			}
			cout << min << ":";
			if (sec<10)
			{
				cout << "0";
			}
			cout << sec << endl;
		}
		else
		{
			cout << "Signals fail to synchronise in 5 hours" << endl;
		}
	}
}
