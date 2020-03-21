#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	int n;
	while (cin >> n)
	{
		int arr[1000];// s[1000];
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
			//s[i] = arr[i];
		}
		int counter = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n-i-1; j++)
			{
				if (arr[j]>arr[j+1])
				{
					counter++;
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		/*sort(s, s + n);
		int counter = 0;
		for (int i = n-1; i >= 0; i--)
		{
			if (arr[i]!=s[i])
			{
				counter++;
				for (size_t j = 0; j < n; j++)
				{
					if (arr[j]==s[i])
					{
						int temp = arr[j];
						arr[j] = arr[i];
						arr[i] = temp;
						break;
					}
				}
			}
		}*/

		cout << "Minimum exchange operations : " << counter << endl;
	}
}
