#include <iostream>
#include <algorithm>
using namespace std;
void sortt(int list[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (list[i]<list[j])
			{
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}
int cheker(int list[],int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (list[i]!=i+1)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int a;
	while (cin >> a)
	{
		int arr[10000],ary[10000];
		for (size_t i = 0; i < a; i++)
		{
			cin >> arr[i];
		}
		for (size_t i = 0; i < (a - 1); i++)
		{
			ary[i] = arr[i] - arr[i + 1];
			if (ary[i]<0)
			{
				ary[i] = ary[i]*(-1);
			}
		}
		sortt(ary,a-1);
		if (cheker(ary,a-1)==1)
		{
			cout << "Not jolly" << endl;
		}
		else
		{
			cout << "Jolly" << endl;
		}
	}
	system("pause>A");
}
