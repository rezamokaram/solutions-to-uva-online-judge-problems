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
ll k, q, nq;
ll a, b, x, y, nx, ny;
bool il()
{
	int s=q, ss=nq;
	if (ss<s)
	{
		swap(s, ss);
	}
	if ((a==x && a==nx) || (b==y && b==ny))
	{
		if (k>=s && k<=ss)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{

	while (cin >> k >> q >> nq)
	{
		a = k / 8;
		b = k % 8;
		x = q / 8;
		y = q % 8;
		nx = nq / 8;
		ny = nq % 8;
		if (k == q)
		{
			cout << "Illegal state" << endl;
		}
		else if (q == nq || /*k == nq || */(x != nx && ny != y))
		{
			cout << "Illegal move" << endl;
		}
		else if (il())
		{
			cout << "Illegal move" << endl;
		}
		else if (abs(k-nq)==8 || (abs(k-nq)==1 && a == nx))
		{
			cout << "Move not allowed" << endl;
		}
		else if ((k == 0 && nq == 9) || (k == 7 && nq == 14) || (k == 56 && nq == 49) || (k == 63 && nq == 54))
		{
			cout << "Stop" << endl;
		}
		else
		{
			cout << "Continue" << endl;
		}
	}
}
