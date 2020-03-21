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
int main()
{
	int tc = 0;
	cin >> tc;
	while (tc--)
	{
		int py, sl, dr;
		cin >> py >> sl >> dr;
		if (py<=0)
		{
			for (size_t i = 0; i < sl; i++)
			{
				int a, b;
				cin >> a >> b;
			}
			for (size_t i = 0; i < dr; i++)
			{
				int a;
				cin >> a;
			}
		}
		else
		{


			vector<int> player;
			for (size_t i = 0; i < py; i++)
			{
				player.push_back(1);
			}
			int list[100000][2];
			for (size_t i = 0; i < sl; i++)
			{
				int start, end;
				cin >> start >> end;
				list[i][0] = start;
				list[i][1] = end;
			}
			bool process = true;
			for (size_t i = 0; i < dr; i++)
			{
				int die;
				cin >> die;
				if (process)
				{
					player[i%py] += die;
					if (player[i%py] > 100)
					{
						player[i%py] = 100;
					}
					
					for (size_t j = 0; j < sl; j++)
					{
						if (list[j][0] == player[i%py])
						{
							player[i%py] = list[j][1];
							break;
						}
					}
					if (player[i%py] == 100)
					{
						process = false;
						continue;
					}
				}
			}
			for (size_t i = 0; i < py; i++)
			{
				cout << "Position of player " << i + 1 << " is " << player[i] << "." << endl;
			}
		}
	}
}
