#include <iostream>
using namespace std;
int main()
{
	int n;
	for (int z=0;cin >> n;z++)
	{
		if (n==0)
		{
			break;
		}
		if (z!=0)
		{
			cout << "\n";
		}
		int arr[1000];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int temp = n - 5;
		for (size_t i1 = 0; i1 < temp; i1++)
		{
			for (size_t i2 = i1; i2 < temp; i2++)
			{
				for (size_t i3 = i2; i3 < temp; i3++)
				{
					for (size_t i4 = i3; i4 < temp; i4++)
					{
						for (size_t i5 = i4; i5 < temp; i5++)
						{
							for (size_t i6 = i5; i6 < temp; i6++)
							{
								cout << arr[i1 + 0] << " " << arr[i2 + 1] << " " << arr[i3 + 2] << " " << arr[i4 + 3] << " " << arr[i5 + 4] << " " << arr[i6 + 5] << "\n";
							}
						}
					}
				}
			}
		}
	}
	system("pause>A");
}
