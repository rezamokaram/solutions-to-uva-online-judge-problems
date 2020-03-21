#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b<a)
		{
			int d = a;
			a = b;
			b = d;
		}
		if (a%2==0)
		{
			a++;
		}
		long long int sum = 0;
		for (long long j = a; j <= b; j+=2)
		{
			sum += j;
		}
		cout <<"Case "<<i+1<<": "<< sum << "\n";
	}
	system("pause>A");
}
