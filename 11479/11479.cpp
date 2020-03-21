#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void sortt(long long int list[])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (list[j]>list[j+1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
int main()
{
	long long int a[3], n;
	cin >> n;
	for (long long int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2];
		sortt(a);
		if (a[0] + a[1] > a[2] && a[0] > 0 && a[1]>0 && a[2]>0 && (a[1] - a[0]) < a[2])
		{
			if (a[0] == a[1] && a[1] == a[2])
			{
				cout << "Case " << i + 1 << ": Equilateral\n";
			}
			else if (a[0] == a[1] && a[1] != a[2] || a[0] != a[1] && a[1] == a[2])
			{
				cout << "Case " << i + 1 << ": Isosceles\n";
			}
			else //if (a[0] != a[1] && a[1] != a[2])
			{
				cout << "Case " << i + 1 << ": Scalene\n";
			}
		}
		else
		{
			cout << "Case " << i + 1 << ": Invalid\n";
		}
	}
	system("pause>A");
}

