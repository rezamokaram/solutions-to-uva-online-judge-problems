#include <iostream>
#include <string>
using namespace std;
int f(int x)
{
	if (x>=101)
	{
		return (x - 10);
	}
	else if (x<=100)
	{
		return f(f(x + 11));
	}
}
int main()
{
	int a;
	while (cin>>a)
	{
		if (a==0)
		{
			break;
		}
		cout << "f91("<<a<<") = " << f(a) << endl;
	}
	system("pause>A");
}
