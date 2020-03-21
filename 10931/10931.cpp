#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;



int main()
{
	int n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		int sum = 0,i, a[100000];
		for (i = 0; n > 0; i++)
		{
			a[i]= (n % 2);
			sum += (n % 2);
			n /= 2;
		}
		cout << "The parity of ";
		for (int j = i-1; j >= 0 ; j--)
		{
			cout << a[j];
		}
		cout << " is " << sum << " (mod 2).\n";
	}
}
