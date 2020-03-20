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
	int h, d, f;
	float u;
	while (cin >> h >> u >> d >> f)
	{
		if (h==0)
		{
			break;
		}
		float temp = 0;
		float fa = u * f / 100;
		for (size_t day = 1; true ; day++)
		{
			temp += u;
			if (u>0)
			{
			u -= fa;
			}
			if (temp>h)
			{
				cout << "success on day " << day << endl;
				break;
			}
			temp -= d;
			if (temp<0)
			{
				cout << "failure on day " << day << endl;
				break;
			}
		}

	}
}
