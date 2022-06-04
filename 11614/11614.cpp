# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
# include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
int main()
{
	ll tc;
	cin >> tc;
	while (tc--)
	{
		llu number;
		cin >> number;
		if (!number)
		{
			cout << 0 << endl;
			continue;
		}
		llu mnumber = number*2;
		mnumber -= 1;
		mnumber = sqrt(mnumber);
		llu low, high;
		low = ((mnumber + 1) * mnumber) / 2;
		high = low + mnumber + 1;
		if (number >= high)cout << mnumber + 1 << endl;
		else if (number >= low)cout << mnumber << endl;
		else cout << mnumber - 1 << endl;
	}
}
