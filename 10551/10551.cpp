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
int main()
{
	int b;
	while (cin >> b && b)
	{
		string num,mod;
		cin >> num >> mod;
		//
		llu m = 0;
		for (size_t i = 0; i < mod.length(); i++)
		{
			m *= b;
			m += mod[i] - '0';
		}
		llu ans = 0;
		for (size_t i = 0; i < num.length(); i++)
		{
			ans *= b;
			ans += num[i] - '0';
			ans %= m;
		}
		if (ans==0)
		{
			cout << 0 << endl;
			continue;
		}
		string show;
		bool f = 0;
		while (ans)
		{
			show.push_back('0' + ans % b);
			ans /= b;
		}
		for (int i = show.length() - 1; i >= 0; i--	)
		{
			cout << show[i];
		}
		cout << endl;
	}
}
