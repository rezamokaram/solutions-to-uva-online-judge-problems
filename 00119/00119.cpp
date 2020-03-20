#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;

int findindex(vector<string> list,string name, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (name==list[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int n;
	bool f = false;
	while (cin >> n)
	{
		vector<string> list;
		for (size_t i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			list.push_back(temp);
		}
		int arr[11] = { 0 };
		string name;
		for (size_t j = 0; j < n; j++)
		{
			cin >> name;
			int money;
			cin >> money;
			int index = findindex(list, name, n);
			arr[index] -= money;
			//
			int npep;
			cin >> npep;
			if (npep==0)
			{
				arr[index] += money;
			}
			string nname;
			int gift;
			if (npep != 0)
			{
				gift = money / npep;
				arr[index] += (money - (gift*npep));
			}
			//
			for (size_t i = 0; i < npep; i++)
			{
				cin >> nname;
				int nindex = findindex(list, nname, n);
				arr[nindex] += gift;
			}
		}
		if (f==true)
		{
			cout << endl;
		}
		f = true;
		for (size_t i = 0; i < n; i++)
		{
			cout << list[i] << " " << arr[i] << endl;
		}
	}
}
