#include <iostream>
#include <string>
//#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;

int value(char list[])
{
	if (list[0]>='2' && list[0]<='9')
	{
		int a = list[0] - '0';
		return a;
	}
	return 10;
}

int main()
{
	int tc;
	cin >> tc;
	for (size_t z = 0; z < tc; z++)
	{
		char card[52][3];
		for (size_t i = 0; i < 52; i++)
		{
			cin >> card[i];
		}
		int valall = 0;
		//
		int mtc = 0;
		for (size_t i = 0; i < 25; i++)
		{
			if (card[i][0] == ',')
			{
				continue;
			}
			int x = value(card[i]);
			card[i][0] = ',';
			valall += x;
			mtc++;
			int ld = 0;
			for (size_t j = 0; ld < (10-(x)); j++)
			{
				if (card[i + j][0]==',')
				{
					continue;
				}
				card[i + j][0] = ',';
				ld++;
			}
			//i += 10 - x;
			if (mtc>=3)
			{
				break;
			}
		}
		int la = 0;
		for (size_t i = 0; i < 52; i++)
		{
			if(card[i][0] == ',')
			{
				continue;
			}
			if (la==valall)
			{
				cout << "Case " << z + 1 << ": " << card[i-1] << endl;
				break;
			}
			la++;
			
		}
		//cout << valall << endl;
	}
}
