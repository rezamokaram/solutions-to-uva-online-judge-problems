#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<string>month_name(12);
int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int getm(string name)
{
	for (int i = 0; i < 12; i++)
		if (name==month_name[i])
			return i + 1;
	return -1;
}
int main()
{
	month_name[0] = "January";
	month_name[1] = "February";
	month_name[2] = "March";
	month_name[3] = "April";
	month_name[4] = "May";
	month_name[5] = "June";
	month_name[6] = "July";
	month_name[7] = "August";
	month_name[8] = "September";
	month_name[9] = "October";
	month_name[10] = "November";
	month_name[11] = "December";
	ll n;
	cin >> n;
	int cs = 0;
	while (n--)
	{
		string name;
		char sine;
		ll fm, fd, fy, sm, sd, sy;
		cin >> name >> fd >> sine >> fy;
		fm = getm(name);
		cin >> name >> sd >> sine >> sy;
		sm = getm(name);
		int ans = 0;
		if (fm > 2)fy++;
		if (sm < 2 || (sm == 2 && sd < 29))sy--;
		ans += sy / 4 - (fy - 1) / 4;
		ans -= sy / 100 - (fy - 1) / 100;
		ans += sy / 400 - (fy - 1) / 400;
		cout << "Case " << ++cs << ": " << ans << endl;
	}
}
