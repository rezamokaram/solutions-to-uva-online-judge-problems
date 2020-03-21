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
bool srch(int numbers[], int x)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (x==numbers[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int sis[3];
	int bro[2];
	while (cin  >>sis[0]>>sis[1]>>sis[2]>>bro[0]>>bro[1] && sis[0] && sis[1] && sis[2] && bro[0] && bro[1])
	{
		sort(sis, sis + 3);
		sort(bro, bro + 2);
		int numbers[5] = { sis[0],sis[1],sis[2],bro[0],bro[1] };
		sort(numbers, numbers + 5);
		//losses
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (sis[j]!=-1 && bro[i]!=-1)
				{
					if (sis[j]>bro[i])
					{
						sis[j] = bro[i] = -1;
						break;
					}
				}
			}
		}
		//wins
		int win = 0;
		for (int i = 1; i >= 0; i--)
		{
			for (size_t j = 0;  j < 3;  j++)
			{
				if (sis[j] != -1 && bro[i] != -1)
				{
					sis[j] = bro[i] = -1;
					win++;
				}
			}
		}
		//
		bool f = false;
		if (win == 0)
		{
			cout << -1 << endl;
			continue;
		}
		else if (win == 1)
		{
			bool dd = false;
			int min = 1;
			for (size_t i = 0; i < 3; i++)
			{
				if (sis[i]!=-1)
				{
					min = sis[i];
					dd = true;
					break;
				}
			}
			if (!dd)
			{
				f = true;
			}
			for (int i = min+1; i < 54 && !f; i++)
			{
				if (i==53)
				{
					f = true;
					break;
				}
				if (!srch(numbers,i))
				{
					cout << i << endl;
					break;
				}
			}
		}	
		else//win == 2
		{
			for (int i = 1; i < 54; i++)
			{
				if (i==53)
				{
					break;
				}
				if (!srch(numbers, i))
				{
					cout << i << endl;
					break;
				}
			}
		}
		if (f)
		{
			cout << -1 << endl;
		}
	}
}
