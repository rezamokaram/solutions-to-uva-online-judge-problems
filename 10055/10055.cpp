#include <iostream>
using namespace std;
int main()
{
	long long int a, b,n;
	while (cin >>a>>b)
	{
		if (b>a)
		{
			n = a;
			a = b;
			b = n;
		}
		cout << a - b << "\n";
	}
	system("pause>A");
}
