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
	char a;
	while (cin >> a)
	{
		vector<char>b(5);
		b[0] = a;
		for (size_t i = 1; i < 5; i++)
		{
			cin >> b[i];
		}
		bool f = 1;
		for (size_t i = 0; i < 5; i++)
		{
			cin >> a;
			if (a==b[i])
			{
				f = 0;
			}
		}
		if (f)
		{
			cout << "Y" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
}
