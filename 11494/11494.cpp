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
int a, b, x, y;
bool in_a_row()
{
	int fx = abs(a - x);
	int fy = abs(b - y);
	if (fx==fy)
	{
		return 1;
	}
	return 0;
}
int main()
{

	while (cin >> a >> b >> x >> y && a && b && x && y)
	{
		if (a==x && b==y)
		{
			cout << 0 << endl;
			continue;
		}
		else if (a==x || b==y || in_a_row())
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
}
