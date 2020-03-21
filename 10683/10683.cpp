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
const int minu = 86400, hour = 8640000, sec=864;
int main()
{
	llu n;
	while (cin >> n)
	{
		ll sum = 0;
		sum += (n % 100) * 10;
		n /= 100;
		sum += (n % 100) * 1000;
		n /= 100;
		sum += (n % 100) * 60000;
		n /= 100;
		sum += (n % 100) * 3600000;
		n /= 100;
		//cout << sum/10 << endl;
		cout << sum / hour;
		sum %= hour;
		if ((sum / minu) < 10)cout << 0;
		cout << sum / minu;
		sum %= minu;
		///////////
		if (sum / sec < 10)cout << 0;
		cout << sum / sec;
		sum %= sec;
		if (sum * 100 / sec < 10)cout << 0;
		cout << sum * 100 / sec << endl;
	}
}
