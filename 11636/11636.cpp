#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int ans(int number)
{

	int counter=0;
	int arr[15][2];
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[1][0] = 1;
	arr[1][1] = 0;
	for (size_t i = 2; i < 15; i++)
	{
		
		arr[i][0] = arr[i - 1][0] * 2;
		counter++;
		arr[i][1] = 1 + arr[i-1][1];
		
	}
	for (int i = 14; i >= 0; i--)
	{
		if (number > arr[i][0])
		{
			return 1 + arr[i][1];
		}
		else if (number==arr[i][0])
		{
			return arr[i][1];
		}
		else
		{
			continue;
		}
	}
}


int main()
{
	int a;
	for (size_t t=1;cin >> a;t++)
	{
		if (a < 0)
		{
			break;
		}
		else
		{
			cout << "Case " << t << ": " << ans(a) << endl;
		}
	}
}
