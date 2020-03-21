#include <iostream>
#include <cmath>
using namespace std;
void sort(int list[])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3-i-1; j++)
		{
			if (list[j] > list[j+1])
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
	int arr[3];
	while (cin >> arr[0] >> arr[1] >> arr[2])
	{
		if (arr[1]==0 && arr[2]==0 && arr[0]==0)
		{
			break;
		}
		sort(arr);
		if ((arr[2]*arr[2])==(arr[1]*arr[1])+(arr[0]*arr[0]))
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
	system("pause>A");
}
