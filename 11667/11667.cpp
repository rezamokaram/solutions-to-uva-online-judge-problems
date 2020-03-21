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
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int gcd(int a, int b) { return(b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return(a*b / gcd(a, b)); }
//
int main()
{
	ll h, m, hh, mm;
	while (cin >> h >> m >> hh >> mm)
	{
		if (mm==0 && h==0 && m==0 && hh==0)
			break;
		m += h * 60;
		mm += hh * 60;
		if (m > mm)mm += 1440;
		cout << mm - m << endl;
	}
}
