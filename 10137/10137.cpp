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
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<ll>money;
		ll sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			ll d, c;
			char sine;
			cin >> d >> sine >> c;
			money.push_back(d * 100 + c);
			sum += money[i];
		}
		ll low = sum / n;
		ll high = low + (sum%n ? 1 : 0);
		ll highsum = 0, lowsum = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (money[i]>high)
			{
				highsum += money[i] - high;
			}
			if (money[i]<low)
			{
				lowsum += low - money[i];
			}
		}
		ll ans = 0;
		if (highsum>lowsum)
		{
			ans = highsum;
		}
		else
		{
			ans = lowsum;
		}
		cout << "$" << (ans / 100) << ".";
		ans %= 100;
		if (ans<10)
		{
			cout << 0;
		}
		cout << ans << endl;
	}
}
