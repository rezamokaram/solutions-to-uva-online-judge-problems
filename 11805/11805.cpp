#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;


int main()
{
	int tc;
	cin >> tc;
	int z = 1;
	while (z <= tc)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = ((b + c) % (a));
		if (ans==0)
		{
			ans = a;
		}
		cout << "Case " << z << ": " << ans << endl;
		z++;
	}
}
