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
	int a;
	while (cin >> a)
	{
		int arr[5] = { 0 };
		for (size_t i = 0; i < 5; i++)
		{
			int temp;
			cin >> temp;
			arr[temp - 1]++;
		}
		cout << arr[a - 1] << endl;
	}
}
