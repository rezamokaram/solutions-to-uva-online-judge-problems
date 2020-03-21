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
int top = 1, down = 6, north = 5, south = 2, east = 3, west = 4;
void n()
{
	swap(top, north);
	swap(north, down);
	swap(down, south);
}
void s()
{
	swap(top, south);
	swap(south, down);
	swap(down, north);
}
void e()
{
	swap(top, east);
	swap(east, down);
	swap(down, west);
}
void w()
{
	swap(top, west);
	swap(west, down);
	swap(down, east);
}
//
int main()
{
	int tc;
	while (cin >> tc && tc)
	{
		top = 1;
		down = 6;
		north = 5;
		south = 2;
		east = 3;
		west = 4;
		while (tc--)
		{
			string temp;
			cin >> temp;
			if (temp == "north")
			{
				n();
			}
			else if (temp == "south")
			{
				s();
			}
			else if (temp == "west")
			{
				w();
			}
			else
			{
				e();
			}
		}
		cout << top << endl;
	}
}
