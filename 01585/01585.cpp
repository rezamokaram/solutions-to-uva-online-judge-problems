#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		char a[10000];
		int b[10000];
		cin >> a;
		int t;
		for ( t = 0; a[t] ; t++);
		if (a[0]=='X')
		{
			b[0] = 0;
		}
		else if (a[0]=='O')
		{
			b[0] = 1;
		}
		int sum = 0;
		for (size_t j = 1; j < t; j++)
		{
			if (a[j]=='X')
			{
				b[j] = 0;
			}
			else if (a[j]=='O')
			{
				b[j] = b[j - 1] + 1;
			}
			sum += b[j];
		}
		cout << sum + b[0] << "\n";
	}
	system("pause>A");
}
