#include<iostream>
using namespace std;
int main()
{
	int n,ary[100];
	cin >> n;
	cout << "Lumberjacks:" << "\n";
	for (size_t i = 0; i < n; i++)
	{
		int arr[10];
		for (size_t j = 0; j < 10; j++)
		{
			cin >> arr[j];
		}
		int d = 0;
		for (size_t j = 0; j < 9; j++)
		{
			if (arr[j]>arr[j+1])
			{
				d++;
			}
		}
		if (d==0 || d==9)
		{
			cout << "Ordered" << "\n";
		}
		else
		{
			cout << "Unordered" << "\n";
		}
	}
	system("pause>A");
}
