#include <iostream>
#include <iomanip>
using namespace std;
int sd(int n)
{
	int sum = 0, j, d;
	do
	{
		if (n <= 0)
		{
			n = sum;
			sum = 0;
		}
		for (; n > 0;)
		{
			sum += n % 10;
			n = n / 10;
		}
		d = sum;
		for (j = 0; d > 0; j++)
		{
			d = d / 10;

		}
	} while (j > 1);
	return sum;
}
int main()
{
	char a[100], b[1000];
	for (size_t i = 0; cin.getline(a, 100); i++)
	{
		cin.getline(b, 100);
		int sum1 = 0, sum2 = 0;
		for (size_t z = 0; a[z]; z++)
		{
			if (a[z] >= 'a' && a[z] <= 'z')
			{
				sum1 += (a[z] - 96);
			}
			else if (a[z] >= 'A' && a[z] <= 'Z')
			{
				sum1 += (a[z] - 64);
			}
		}
		for (size_t z = 0; b[z]; z++)
		{
			if (b[z] >= 'a' && b[z] <= 'z')
			{
				sum2 += (b[z] - 96);
			}
			else if (b[z] >= 'A' && b[z] <= 'Z')
			{
				sum2 += (b[z] - 64);
			}
		}
		double l, l1 = sd(sum1), l2 = sd(sum2);
		if (l2 >= l1)
		{
			l = l1 / l2;
		}
		else
		{
			l = l2 / l1;
		}
		//cout << sum1 << " " << sum2 << "\n";
		//cout << sd(sum1) << " " << sd(sum2) << "\n";
		cout <<fixed<<setprecision(2)<< l * 100 << " %" << "\n";
	}
	system("pause>A");
}
