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
int main()
{
	int tc;
	cin >> tc;
	int d=1;
	while (tc--)
	{
		double a, b, c;
		cin >> a >> b >> c;
		double temp = (c*(a + a - b)) / (a + b);
		int money = temp;
		if (money<=0)
		{
			money = 0;
		}
		cout << money << endl;
	}
}
