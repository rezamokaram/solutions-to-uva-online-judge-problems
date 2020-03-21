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

//
int main()
{
	int n;
	while (cin >> n)
	{
		int counter = 0;
		int arr[100000];
		int arry[100001];
		ll sum = 0;
		//
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			arry[i] = arr[i];
			if (i>0)
			{
				arry[i] += arry[i - 1];
			}
		}
		if (sum % 3 != 0)
		{
			cout << 0 << endl;
			continue;
		}
		sum /= 3;
		//
		
		int nns = 0;
		for (size_t i = 0; nns < sum; i++)
		{
		
			nns += arr[i];
			
			int temp = binary_search(arry , arry + n, (nns + sum));
			int temp2 = binary_search(arry, arry + n, (nns + sum + sum));
			if (temp > 0 && temp2 > 0)
			{
				counter++;
			}
		}
		cout << counter << endl;
	}
}
