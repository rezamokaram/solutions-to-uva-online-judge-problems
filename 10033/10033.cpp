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
int const big = 1000;
int main()
{
	ll tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	bool popo = 0;
	while (tc--)
	{
		if (popo)
		{
			cout << endl;
		}
		popo = 1;
		vector<string>ram(1011, "000");
		int index = 0;
		while (getline(cin, ram[index++]))
		{
			if (ram[index - 1] == "")
			{
				ram[index - 1] = "000";
				break;
			}
		}
		int gam = 0;
		bool fff = 1;
		int ans = 0;
		int reg[11] = { 0 };
		while (fff /*&& gam<=1000*/)
		{
			if (fff==0)
			{
				break;
			}
			bool ff = 1;
			int h, f, d;
			h = ram[gam][0] - '0';
			f = ram[gam][1] - '0';
			d = ram[gam][2] - '0';
			//
			if (ram[gam] == "100")
			{
				//halt
				fff = 0;
				ans++;
				break;
			}
			else if (h == 0)
			{
				if (reg[d] != 0)
				{
					ff = 0;
					gam = reg[f];
				}
				ans++;

			}
			else if (h == 1)
			{
				ans++;
			}
			else if (h == 2)
			{
				reg[f] = d;
				ans++;
			}
			else if (h == 3)
			{
				reg[f] += d;
				reg[f] %= big;
				ans++;
			}
			else if (h == 4)
			{
				reg[f] *= d;
				reg[f] %= big;
				ans++;
			}
			else if (h == 5)
			{
				reg[f] = reg[d];
				ans++;
			}
			else if (h == 6)
			{
				reg[f] += reg[d];
				reg[f] %= big;
				ans++;
			}
			else if (h == 7)
			{
				reg[f] *= reg[d];
				reg[f] %= big;
				ans++;
			}
			else if (h == 8)
			{
				reg[f] = stoi(ram[reg[d]]);
				ans++;
			}
			else//9
			{
				string temp;
				temp.push_back('0' + reg[f] / 100);
				temp.push_back('0' + (reg[f] / 10) % 10);
				temp.push_back('0' + reg[f] % 10);
				ram[reg[d]] = temp;
				ans++;
			}
			if (ff)
			{
				gam++;
			}
		}
		cout << ans << endl;
	}
}
