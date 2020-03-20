#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	int h;
	double m;
	char sine;
	while (cin >> h >> sine >> m)
	{
		if (h==0 && m==0)
		{
			break;
		}
		double hh = 0, mm = 0;
		mm = m * 6;
		hh = h * 30 + (m / 2);
		double deg;
		if (mm>hh)
		{
			deg = mm - hh;
		}
		else
		{
			deg = hh - mm;
		}
		if (deg>180)
		{
			double temp = deg - 180;
			deg -= 2 * temp;
		}
		cout << fixed << setprecision(3) << deg << endl;
	}
}
