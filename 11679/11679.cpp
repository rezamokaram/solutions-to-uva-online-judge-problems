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
//
int main()
{
	int b, n;
	while (cin >> b >> n && b && n)
	{
		vector<int>banks(b);
		for (size_t i = 0; i < b; i++)
		{
			int temp;
			cin >> temp;
			banks[i] = temp;
		}
		for (size_t i = 0; i < n; i++)
		{
			int fb, sb, val;
			cin >> fb >> sb >> val;
			banks[fb - 1] -= val;
			banks[sb - 1] += val;
		}
		bool f = 1;
		for (size_t i = 0; i < b; i++)
		{
			if (banks[i]<0)
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			cout << "S" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
}
