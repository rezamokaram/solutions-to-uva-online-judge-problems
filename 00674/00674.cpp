//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const ll MAX = 9999999999;
//
const ll th = 7491;
int arr[5][th] = { 0 };
int main()
{
	int coin[] = { 1,5,10,25,50 };
	for (size_t i = 0; i < th; i++)
	{
		arr[0][i] = 1;
	}
	arr[1][0] = arr[2][0] = arr[3][0] = arr[4][0] = 1;
	for (size_t i = 1; i < 5; i++)
	{
		for (size_t j = 0; j < th; j++)
		{
			arr[i][j] = arr[i - 1][j];
			if (j>=coin[i])
			{
				arr[i][j] += arr[i][j - coin[i]];
			}
		}
	}
	int d;
	while (cin >> d)cout << max(max(max(arr[0][d],arr[1][d]),max(arr[2][d],arr[3][d])),arr[4][d]) << endl;
}
