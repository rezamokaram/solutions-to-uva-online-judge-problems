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
bool vt(double list[])
{
	if (list[0]+list[1]>list[2])
	{
		return true;
	}
	else
	{
		return false;
	}
}
//
int main()
{
	double a[3];
	while (cin >> a[0] >> a[1] >> a[2])
	{
		sort(a, a + 3);
		if (vt(a))
		{
			double p = a[0] + a[2] + a[1];
			p /= 2;
			double ans = p * (p - a[0])*(p - a[1])*(p - a[2]);
			ans=sqrt(ans);
			ans *= 4.0 / 3.0;
			cout << fixed << setprecision(3) << ans << endl;
		}
		else
		{
			cout << "-1.000" << endl;
		}
	}
}
