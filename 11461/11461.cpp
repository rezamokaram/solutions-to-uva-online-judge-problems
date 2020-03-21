#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long unsigned int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		int counter = 0;
		for (long long unsigned int i = 1; i > 0 ; i++)
		{
			if ((i*i) >= a && (i*i) <= b)
			{
				counter++;
			}
			if ((i*i) >= b)
			{
				break;
			}
		}
		cout << counter << endl;
	}
	system("pause>A");
}
