#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;

int main()
{
	llu arr[10001];
	int counter = 0;
	while (cin >> arr[counter])
	{
		counter++;
		if (counter==1)
		{
			cout << arr[0] << endl;
			continue;
		}
		sort(arr, arr + counter);
		int temp = 0;
		if (counter%2==1)
		{
			int temp = (counter / 2);
			cout << arr[temp] << endl;
		}
		else
		{
			int temp = (arr[counter / 2] + arr[(counter / 2) - 1]) / 2;
			cout << temp << endl;
		}
	}
}
