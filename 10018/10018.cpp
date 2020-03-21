#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
long long int revers(long long int x)
{
	long long int lenght=0,temp = x;
	for ( lenght = 0; temp > 0 ; lenght++)
	{
		temp /= 10;
	}
	lenght--;
	long long int Revers = 0;
	for (;  0 <= lenght ;lenght--)
	{
		Revers += (x % 10)*(pow(10, lenght));
		x /= 10;
	}
	return Revers;
}
int main()
{
	long long int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int counter = 0;
		long long int x;
		cin >> x;
		while (1>0)
		{
			x += revers(x);
			counter++;
			if (x==revers(x))
			{
				break;
			}
		}
		cout << counter << " " << x << endl;
	}
	system("pause>A");
}
