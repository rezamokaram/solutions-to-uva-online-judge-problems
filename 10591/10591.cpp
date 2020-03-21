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
int happy(int a)
{
	int sum = 0;
	while (a>0)
	{
		double digit = a % 10;
		sum += pow(digit, 2);
		a /= 10;
	}
	return sum;
}
//
int main()
{
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int d;
		int temp;
		cin >> d;
		temp = d;
		bool f = false;
		int q = 0;
		int arr[10000];
		while (true)
		{
			arr[q] = d;
			q++;
			
			if (d==1)
			{
				f = true;
				break;
			}
			else if (d == temp && q>1)
			{
				break;
			}
			d = happy(d);
			int index = binary_search(arr, arr + q, d);
			if (index>0)
			{
				break;
			}
		}
		if (f)
		{
			cout << "Case #" << i + 1 << ": " << temp << " is a Happy number." << endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": " << temp << " is an Unhappy number." << endl;
		}
	}
}
