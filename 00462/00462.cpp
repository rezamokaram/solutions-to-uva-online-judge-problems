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
char list[13][3];
int number_card_suit(char suit)
{
	int sum = 0;
	for (size_t i = 0; i < 13; i++)
	{
		if (list[i][1] == suit)
		{
			sum++;
		}
	}
	return sum;
}
//
int main()
{

	while (cin >> list[0])
	{
		bool f = false, ff = false, fff = false, ffff = false;
		for (size_t i = 1; i < 13; i++)
		{
			cin >> list[i];
		}
		int marks = 0, markh = 0, markd = 0, markc = 0;
		//hand s
		int ns = number_card_suit('S');
		for (size_t i = 0; i < 13; i++)
		{
			if (list[i][1] != 'S')
			{
				continue;
			}
			if (list[i][0] == 'A')
			{
				f = true;
				marks += 4;
			}
			else if (list[i][0] == 'K')
			{		
				marks += 3;
				if (ns <= 1)
				{
					marks--;
				}
				else
				{
					f = true;
				}
			}
			else if (list[i][0] == 'Q')
			{
				marks += 2;
				if (ns <= 2)
				{
					marks--;
				}
				else
				{
					f = true;
				}
			}
			else if (list[i][0] == 'J')
			{
				marks++;
				if (ns <= 3)
				{
					marks--;
				}
			}
		}
		//hand h
		int nh = number_card_suit('H');
		for (size_t i = 0; i < 13; i++)
		{
			if (list[i][1] != 'H')
			{
				continue;
			}
			if (list[i][0] == 'A')
			{
				ff = true;
				markh += 4;
			}
			else if (list[i][0] == 'K')
			{
				markh += 3;
				if (nh <= 1)
				{
					markh--;
				}
				else
				{
					ff = true;
				}
			}
			else if (list[i][0] == 'Q')
			{
				markh += 2;
				if (nh <= 2)
				{
					markh--;
				}
				else
				{
					ff = true;
				}
			}
			else if (list[i][0] == 'J')
			{
				markh++;
				if (nh <= 3)
				{
					markh--;
				}
			}
		}
		//hand d
		int nd = number_card_suit('D');
		for (size_t i = 0; i < 13; i++)
		{
			if (list[i][1] != 'D')
			{
				continue;
			}
			if (list[i][0] == 'A')
			{
				fff = true;
				markd += 4;
			}
			else if (list[i][0] == 'K')
			{
				markd += 3;
				if (nd <= 1)
				{
					markd--;
				}
				else
				{
					fff = true;
				}
			}
			else if (list[i][0] == 'Q')
			{
				markd += 2;
				if (nd <= 2)
				{
					markd--;
				}
				else
				{
					fff = true;
				}
			}
			else if (list[i][0] == 'J')
			{
				markd++;
				if (nd <= 3)
				{
					markd--;
				}
			}
		}
		//hand c
		int nc = number_card_suit('C');
		for (size_t i = 0; i < 13; i++)
		{
			if (list[i][1] != 'C')
			{
				continue;
			}
			if (list[i][0] == 'A')
			{
				ffff = true;
				markc += 4;
			}
			else if (list[i][0] == 'K')
			{
				markc += 3;
				if (nc <= 1)
				{
					markc--;
				}
				else
				{
					ffff = true;
				}
			}
			else if (list[i][0] == 'Q')
			{
				markc += 2;
				if (nc <= 2)
				{
					markc--;
				}
				else
				{
					ffff = true;
				}
			}
			else if (list[i][0] == 'J')
			{
				markc++;
				if (nc <= 3)
				{
					markc--;
				}
			}
		}
		//end
		if (f && ff && fff && ffff && (markc + markd + marks + markh) >= 16)
		{
			cout << "BID NO-TRUMP" << endl;
			continue;
		}
		//ignored rules
		if (ns <= 1)
		{
			marks += 2;
		}
		else if (ns == 2)
		{
			marks++;
		}
		if (nh <= 1)
		{
			markh += 2;
		}
		else if (nh == 2)
		{
			markh++;
		}
		if (nd <= 1)
		{
			markd += 2;
		}
		else if (nd == 2)
		{
			markd++;
		}
		if (nc <= 1)
		{
			markc += 2;
		}
		else if (nc == 2)
		{
			markc++;
		}
		//mark
		int arr[4] = { marks,markh,markd,markc };
		//sort(arr[0], 4);
		//int max = arr[3];
		//n
		int arrn[4] = { ns,nh,nd,nc };
		sort(arrn, arrn + 4);
		int maxn = arrn[3];
		//pass
		int pass = marks + markh + markd + markc;
		if (pass < 14)
		{
			cout << "PASS" << endl;
			continue;
		}
		//bid
		cout << "BID ";
		if (ns == maxn)
		{
			cout << "S";
		}
		else if (nh == maxn)
		{
			cout << "H";
		}
		else if (nd == maxn)
		{
			cout << "D";
		}
		else if (nc == maxn)
		{
			cout << "C";
		}
		cout << endl;
	}
}
