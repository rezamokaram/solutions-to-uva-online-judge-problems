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
	int tc;
	cin >> tc;
	for (size_t z = 1; z <= tc; z++)
	{
		char a[9];
		cin >> a;
		int m = 0, d = 0, y = 0;
		m = (a[0] - '0') * 10 + (a[1] - '0');
		d = (a[2] - '0') * 10 + (a[3] - '0');
		y = (a[4] - '0') * 1000 + (a[5] - '0') * 100 + (a[6] - '0') * 10 + (a[7] - '0');
		//
		int mon[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
		bool flag = false;
		if (y%4==0)
		{
			mon[1]++;
			flag = true;
		}
		//
		int x = 280;
		int nd = d, nm = m, ny = y;
		while (x > 0)
		{
			x--;
			nd++;
			if (nd > mon[nm-1])
			{
				nd -= mon[nm - 1];
				nm++;
			}
			if (nm > 12)
			{
				nm -= 12;
				ny++;
				if (flag==true)
				{
					mon[1]--;
				}
				else if (ny%4==0)
				{
					mon[1]++;
				}
			}
		}
		//
		char nnd[3], nnm[3], nny[5];
		int temp = nd/10;
		nnd[0] = '0' + (temp % 10);
		nnd[1] = '0' + (nd % 10);
		nnd[2] = '\0';
		temp = nm / 10;
		nnm[0] = '0' + (temp % 10);
		nnm[1] = '0' + (nm % 10);
		nnm[2] = '\0';
		temp = ny / 1000;
		nny[0] = '0' + (temp % 10);
		temp = ny / 100;
		nny[1] = '0' + (temp % 10);
		temp = ny / 10;
		nny[2] = '0' + (temp % 10);
		temp = ny;
		nny[3] = '0' + (temp % 10);
		nny[4] = '\0';
		//
		if (nd>=21 && nm==1 || nm==2 && nd<=19)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " aquarius" << endl;
		}
		else if (nd >= 20 && nm == 2 || nm == 3 && nd <= 20)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " pisces" << endl;
		}
		else if (nd >= 21 && nm == 3 || nm == 4 && nd <= 20)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " aries" << endl;
		}
		else if (nd >= 21 && nm == 4 || nm == 5 && nd <= 21)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " taurus" << endl;
		}
		else if (nd >= 22 && nm == 5 || nm == 6 && nd <= 21)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " gemini" << endl;
		}
		else if (nd >= 22 && nm == 6 || nm == 7 && nd <= 22)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " cancer" << endl;
		}
		else if (nd >= 23 && nm == 7 || nm == 8 && nd <= 21)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " leo" << endl;
		}
		else if (nd >= 22 && nm == 8 || nm == 9 && nd <= 23)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " virgo" << endl;
		}
		else if (nd >= 24 && nm == 9 || nm == 10 && nd <= 23)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " libra" << endl;
		}
		else if (nd >= 24 && nm == 10 || nm == 11 && nd <= 22)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " scorpio" << endl;
		}
		else if (nd >= 23 && nm == 11 || nm == 12 && nd <= 22)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " sagittarius" << endl;
		}
		else //if (nd >= 23 && nm >= 11 && nm <= 12 && nd <= 22)
		{
			cout << z << " " << nnm << "/" << nnd << "/" << nny << " capricorn" << endl;
		}
	}
}
