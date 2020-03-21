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
void bb(vector<bool>&a)
{
	for (size_t i = 0; i < a.size(); i++)
		a[i] = 0;
	return;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<vector<int>>li(n);
		vector<bool>b(n,0);
		bool f = 1;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				int t;
				cin >> t;
				li[i].push_back(t);
				if (b[t-1])
				{
					f = 0;
				}
				else
				{
					b[t - 1] = 1;
				}
			}
			bb(b);
		}
		if (f)
		{
			for (size_t i = 0; i < n; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					int t = li[j][i];
					if (b[t - 1])
					{
						f = 0;
					}
					else
					{
						b[t - 1] = 1;
					}
				}
				bb(b);
			}
		}
		if (f)
		{
			int const ln = sqrt(n);
			for (size_t i = 0; i < n; i+=ln)
			{
				for (size_t j = 0; j < n; j+=ln)
				{
					for (size_t x = 0; x < ln; x++)
					{
						for (size_t y = 0; y < ln; y++)
						{
							if (b[li[i+x][j+y] - 1])
							{
								f = 0;
							}
							else
							{
								b[li[i + x][j + y] - 1] = 1;
							}
							if (!f)break;
						}
						if (!f)break;
					}
					if (!f)break;
					bb(b);
				}
				if (!f)break;
			}

		}
		if (f)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
