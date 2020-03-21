#include <iostream>
#include <cmath>
using namespace std;
long long unsigned int f(long long unsigned int number)
{
	/*double temp = number;
	int temp1 = sqrt(temp);
	cout << temp1 << endl;*/
	long long unsigned int counter = 0;
	for (long long unsigned int i = 2; i <= number; i++)
	{
		int flag = 0;
		while (number%i==0)
		{
			if (number==0)
			{
				break;
			}
			number /= i;
			flag++;
		}
		if (flag != 0)
		{
			//cout << i << endl<<flag<<endl;
			counter++;
		}
		if (number == 0)
		{
			break;
		}
	}
	return counter;
}
int main()
{
	long long unsigned int a;
	while (cin >> a)
	{
		if (a==0)
		{
			break;
		}
		long long unsigned int temp = f(a);
		if (temp == 0)
		{
			temp++;
		}
		cout << a << " : " << temp << "\n" ;
	}
	system("pause>A");
}
