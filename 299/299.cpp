#include <iostream>
using namespace std;
int sort(int list[], int size)
{
	int counter = 0, flag = 1;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{

				counter++;

				int t = list[j];

				list[j] = list[j + 1];

				list[j + 1] = t;

			}
		}
	}
	return counter;
}
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int k,arr[1000];
		cin >> k;
		for (size_t j = 0; j < k; j++)
		{
			cin >> arr[j];
		}
		cout << "Optimal train swapping takes " << sort(arr, k) << " swaps.\n";
	}
	system("pause>A");
}
