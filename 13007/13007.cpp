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
	int arr[5] = { 1,10,100,1000,10000 };
	int a, b;
	while (cin >>a>>b)
	{
		int we = 0, he = 0;
		for (size_t i = 0; i < b; i++)
		{
			int budget, sumall = 0, first;
			cin >> budget;
			for (size_t j = 0; j < a; j++)
			{
				int temp;
				cin >> temp;
				if (!j)
				{
					first = temp;
				}
				sumall += temp;
			}
			if (budget>=sumall)
			{
				he += first;
			}
			int max = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (budget>=(sumall-first)+arr[j])
				{
					max = arr[j];
				}
			}
			we += max;
		}
		cout << we - he << endl;
	}
}
