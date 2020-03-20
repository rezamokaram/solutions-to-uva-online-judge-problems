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
bool ui(string a, string b)
{
	if (a[0] != b[0])
	{
		if (a[0]=='H')
		{
			return 0;
		}
		else if (a[0]=='S')
		{
			if (b[0]=='H')
			{
				return 1;
			}
			return 0;
		}
		else if (a[0]=='D')
		{
			if (b[0]=='H' || b[0]=='S')
			{
				return 1;
			}
			return 0;
		}
		else//c
		{
			return 1;
		}
	}
	else
	{
		if (a[1]>='0' && a[1]<='9' && b[1]>='0' && b[1]<='9')
		{
			return (a[1] < b[1]);
		}
		else
		{
			if (a[1]>='0' && a[1]<='9')
			{
				return 1;
			}
			else if(b[1]>='0' && b[1]<='9')
			{
				return 0;
			}
			else//both are not number
			{
				if (a[1]=='A')
				{
					return 0;
				}
				else if (a[1]=='K')
				{
					if (b[1]=='A')
					{
						return 1;
					}
					return 0;
				}
				else if (a[1]=='Q')
				{
					if (b[1] == 'A' || b[1]=='K')
					{
						return 1;
					}
					return 0;
				}
				else if (a[1] == 'J')
				{
					if (b[1] == 'A' || b[1]=='K' || b[1]=='Q')
					{
						return 1;
					}
					return 0;
				}
				else//ten
				{
					return 1;
				}
			}
		}
	}
	return false;
}
//
vector<int>turned;
void turn(char d)
{
	/*
	s==1
	w==2
	n==3
	e==4
	*/
	if (d=='N')
	{
		turned.push_back(1);
		turned.push_back(2);
		turned.push_back(3);
		turned.push_back(0);
	}
	else if(d=='W')
	{
		turned.push_back(2);
		turned.push_back(3);
		turned.push_back(0);
		turned.push_back(1);
	}
	else if(d=='S')
	{
		turned.push_back(3);
		turned.push_back(0);
		turned.push_back(1);
		turned.push_back(2);
	}
	else//E
	{
		turned.push_back(0);
		turned.push_back(1);
		turned.push_back(2);
		turned.push_back(3);
	}
}
int main()
{
	char dealer;
	while (cin >> dealer && dealer != '#')
	{
		turned.clear();
		string desk,temp;
		cin >> desk >> temp;
		desk += temp;
		vector<vector<string>>list(4);
		for (size_t i = 0; i < desk.length(); i+=8)
		{
			string a, b, c, d;
			a += desk[i]; a += desk[i + 1];
			list[0].push_back(a);
			b += desk[i + 2]; b += desk[i + 3];
			list[1].push_back(b);
			c += desk[i + 4]; c += desk[i + 5];
			list[2].push_back(c);
			d += desk[i + 6]; d += desk[i + 7];
			list[3].push_back(d);
		}
		for (size_t i = 0; i < 4; i++)
		{
			sort(list[i].begin(), list[i].end(), ui);
		}
		turn(dealer);
		//output
		cout << "S:";
		for (size_t i = 0; i < 13; i++)
		{
			cout << " ";
			cout << list[turned[0]][i];
		}
		cout << endl << "W:";
		for (size_t i = 0; i < 13; i++)
		{
			cout << " ";
			cout << list[turned[1]][i];
		}
		cout << endl << "N:";
		for (size_t i = 0; i < 13; i++)
		{
			cout << " ";
			cout << list[turned[2]][i];
		}
		cout << endl << "E:";
		for (size_t i = 0; i < 13; i++)
		{
			cout << " ";
			cout << list[turned[3]][i];
		}
		cout << endl;
		//end of output
	}
}
