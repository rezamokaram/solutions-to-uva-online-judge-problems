#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int findmax(int list[], int size)
{
	int max = list[0];
	for (size_t i = 0; i < size; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
		}
	}
	return max;
}

int main()
{
	int tc = 0;
	int size[1000];
	vector <string> list;
	string a;
	while (getline(cin, a))
	{
		size[tc] = a.length();
		list.push_back(a);
		tc++;
	}

	for (size_t i = 0; i < findmax(size,tc); i++)
	{
		for (int j = tc - 1; j >= 0; j--)
		{
			if (i<list[j].length())
			{
				cout << list[j][i];
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
