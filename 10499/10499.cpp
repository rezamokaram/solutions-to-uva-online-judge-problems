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
	ll n;
	while (cin >>n && n>=0)
	{
		if (n<=1)
		{
			cout << "0%" << endl;
			continue;
		}
		cout << n * 25 << "%\n";
	}
}
