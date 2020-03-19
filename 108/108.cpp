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
	int n;
	while (cin >> n)
	{
		int mat[100][100];
		//input and make table
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				if (i==0 && j==0)
				{
					continue;
				}
				else if(i==0)
				{
					mat[i][j] += mat[i][j - 1];
				}
				else if(j==0)
				{
					mat[i][j] += mat[i - 1][j];
				}
				else
				{
					mat[i][j] =mat[i][j] + mat[i][j - 1] + mat[i - 1][j] + -mat[i - 1][j - 1];
				}
			}
		}
		//find the max
		ll max = mat[0][0];
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				for (size_t a = i; a < n; a++)
				{
					for (size_t b = j; b < n; b++)
					{
						if (i==0 && j==0)
						{
							ll temp =mat[a][b];
							if (temp > max)
							{
								max = temp;
							}
						}
						else if (i==0)
						{
							ll temp =mat[a][b] - mat[a][j - 1];
							if (temp > max)
							{
								max = temp;
							}
						}
						else if (j==0)
						{
							ll temp = mat[a][b] - mat[i - 1][b];
							if (temp > max)
							{
								max = temp;
							}
						}
						else
						{
							ll temp = mat[i-1][j-1] + mat[a][b] - mat[a][j-1] - mat[i-1][b];
							if (temp > max)
							{
								max = temp;
							}
						}
					}
				}
			}
		}
		//output
		cout << max << endl;
	}
}
