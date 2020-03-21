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
llu sum(llu number)
{
	llu ans;
	if (number%2==0)
	{
		ans = (number + 1)*(number / 2);
	}
	else
	{
		ans = ((number + 1) / 2)*number;
	}
	return ans;
}
int main()
{
	llu n;
	while (cin>>n)
	{
		n = sum(n);
		cout << n*n << endl;
	}
}
