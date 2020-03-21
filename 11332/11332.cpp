#include <iostream>
using namespace std;
int main()
{
	for (size_t i = 0; i < -1; i++)
	{
		long long int n,d,j=10, sum = 0;
		cin >> n;
		if (n==0)
		{
			break;
		}
		while (j > 1)
		{
			if (n<=0)
			{
				n = sum;
				sum = 0;
			}
			for (;n > 0;)
			{
				sum += n % 10;
				n = n / 10;
			}
			d = sum;
			for ( j = 0; d>0; j++)
			{
				d = d / 10;
			}
		}
		cout << sum << "\n";
	}
	system("pause>A");
}
