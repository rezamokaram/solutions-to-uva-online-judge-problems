#include <iostream>
using namespace std;
int main()
{
	char a[1000000];
	while (cin.getline(a,10000))
	{
		for (size_t i = 0; a[i] ; i++)
		{
			a[i] -= 7;
			cout << a[i];
		}
		cout<<"\n";
	}
	system("pause>A");
}
