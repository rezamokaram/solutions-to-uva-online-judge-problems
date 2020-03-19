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
	string str;
	vector <string> list;
	vector <string> listans;
	int arr[1000] = { 0 };
	int vsize = 0;
	int index = 0;
	while (cin >> str)
	{
		if (str=="#")
			break;
		listans.push_back(str);
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i]>='A' && str[i]<='Z')
			{
				str[i] += 32;
			}
		}
		sort(str.begin(), str.end());
		bool f = true;
		for (size_t i = 0; i < vsize; i++)
		{
			if (str==list[i])
			{
				arr[i] = 1;
				arr[vsize] = 1;
				f = false;
				break;
			}
		}
		list.push_back(str);
		vsize++;
	}
	vector <string>ns;
	int d = 0;
	for (size_t i = 0; i < vsize; i++)
	{
		if (arr[i] == 0)
		{
			d++;
			//cout << listans[i] << endl;
			ns.push_back(listans[i]);
		}
	}
	sort(ns.begin(), ns.end());
	for (size_t i = 0; i < d; i++)
	{
		cout << ns[i] << endl;
	}
}
