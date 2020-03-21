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
	int tc;
	cin >> tc;
	int p = 0;
	while (tc--)
	{
		string n;
		cin >> n;
		ll ds = 0;
		vector<int>a(10, 0);
		for (size_t i = 0; i < n.length(); i++)
		{
			a[(n[i] - '0')]++;
			ds += (n[i] - '0');
		}
		bool f = 0;
		while (true)
		{
			int i;
			for ( i = ds%3; i < 10; i+=3)
			{
				if (a[i])
				{
					a[i]--;
					ds -= i;
					break;
				}
			}
			if (i >= 10)break;
			f = 1 - f;
		}
		cout << "Case " << ++p << ": ";
		if (!f)
		{
			cout << "T" << endl;
		}
		else
		{
			cout << "S" << endl;
		}
	}
}
