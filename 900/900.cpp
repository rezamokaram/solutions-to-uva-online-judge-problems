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
llu arr[51] = { 0 };
llu f(llu p)
{
	if (arr[p])
		return arr[p];
	llu main = 0;
	main += f(p-1) + f(p-2);
	arr[p] = main;
	return main;
}
int main()
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	llu d = f(50);
	llu n;
	while (cin >> n && n)
	{
		cout << arr[n] << endl;
	}
}
