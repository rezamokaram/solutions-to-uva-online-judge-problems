#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int al(char a)
{
	//0
	if (a == 'A' || a == 'E' || a == 'O' || a == 'I' || a == 'U' || a == 'H' || a == 'W' || a == 'Y')
	{
		return 0;
	}
	//1
	else if (a == 'B' || a == 'F' || a == 'P' || a == 'V')
	{
		return 1;
	}
	//2
	else if (a == 'C' || a == 'G' || a == 'J' || a == 'Q')
	{
		return 2;
	}
	else if (a == 'K' || a == 'S' || a == 'X' || a == 'Z')
	{
		return 2;
	}
	//3
	else if (a == 'D' || a == 'T')
	{
		return 3;
	}
	//4
	else if (a == 'L')
	{
		return 4;
	}
	//5
	else if (a == 'M' || a == 'N')
	{
		return 5;
	}
	//6
	else if (a == 'R')
	{
		return 6;
	}
	return 0;
}
//
int main()
{
	string temp;
	while (cin >> temp)
	{
		string nstr;
		for (size_t i = 0; i < temp.length(); i++)
		{
			int a = al(temp[i]);
			if (a != 0)
			{
				if (i > 0)
				{
					if (al(temp[i]) != al(temp[i - 1]))
					{
						nstr += '0' + a;
					}
				}
				else
				{
					nstr += '0' + a;
				}
			}
		}
		cout << nstr << endl;
	}
}
