#include <iostream>
#include <cmath>
using namespace std;
int digits(int number)
{
	int counter = 0;
	while (number>0)
	{
		counter++;
		number /= 10;
	}
	return counter;
}
int main()
{
	for (size_t q = 0; q >= 0; q++)
	{
		if (q==0)
		{
			cout << "PERFECTION OUTPUT\n";
		}
		int number;
		cin >> number;
		if (number==0)
		{
			cout << "END OF OUTPUT\n";
			break;
		}
		int sum = 0;
		for (size_t i = 1; i < number; i++)
		{
			if (number%i==0)
			{
				sum += i;
			}
		}
		if (sum==number)
		{
			for (size_t i = digits(number); i < 5; i++)
			{
				cout << " ";
			}
			cout << number << "  PERFECT\n";
		}
		else if (sum>number)
		{
			for (size_t i = digits(number); i < 5; i++)
			{
				cout << " ";
			}
			cout << number << "  ABUNDANT\n";
		}
		else if (sum<number)
		{
			for (size_t i = digits(number); i < 5; i++)
			{
				cout << " ";
			}
			cout << number << "  DEFICIENT\n";
		}
	}
	system("pause>A");
}

