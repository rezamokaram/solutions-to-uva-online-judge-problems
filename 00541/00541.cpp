#include <iostream>
#include <string>
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
	int m;
	while (cin >> m && m)
	{
		int a[100][100];
		int r[100] = { 0 };
		int c[100] = { 0 };
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				r[i] += a[i][j];
				c[i] += a[j][i];
			}
		}
		int R = 0, C = 0, nr = 0, nc = 0;
		for (size_t i = 0; i < m; i++)
		{
			if (r[i] % 2 != 0)
			{
				R++;
				nr = i;
			}
			if (c[i] % 2 != 0)
			{
				C++;
				nc = i;
			}
		}
		if (R==0 && C==0)
		{
			cout << "OK" << endl;
		}
		else if (R==1 && C==1)
		{
			cout << "Change bit (" << nr + 1 << "," << nc + 1 << ")" << endl;
		}
		else
		{
			cout << "Corrupt" << endl;
		}
	}
}
