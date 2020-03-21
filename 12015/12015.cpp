#include <iostream>
using namespace std;
int main()
{
	int arr[10],test;
	char str[10][1000];
	cin >> test;
	for (size_t z = 0; z < test; z++)
	{
		int max = 0;
		for (size_t i = 0; i < 10; i++)
	    {
			cin >> str[i];
			cin >> arr[i];
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		cout << "Case #" << z+1 << ":\n";
		for (size_t i = 0; i < 10; i++)
		{
			if (arr[i] == max )
			{
				cout << str[i] << "\n";
			}
		}
	}
	system("pause>A");
}
