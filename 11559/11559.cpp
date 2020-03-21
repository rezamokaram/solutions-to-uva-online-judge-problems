#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void sortt(int list[], int arr[],int size)
{
	int ary[100];
	for (size_t i = 0; i < size; i++)
	{
		ary[i] = list[i];
		arr[i] = i;
	}
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size-i-1; j++)
		{
			if (ary[j]>ary[j+1])
			{
				int temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int sorttt(int list[], int size)
{
	int x = 9999999999;
	int min = x;
	for (size_t i = 0; i < size; i++)
	{
		if (min>list[i] && list[i]!=-1)
		{
			min = list[i];
		}
	}
	if (min == x)
	{
		return -1;
	}
	return min;
}

int main()
{
	int n, b, h, w;
	while (cin >> n >> b >> h >> w)
	{
		int hotel[100];
		int wek[100][13];
		for (size_t i = 0; i < h; i++)
		{
			cin >> hotel[i];
			for (size_t j = 0; j < w; j++)
			{
				cin >> wek[i][j];
			}
		}
		int sort[100];
		sortt(hotel, sort, h);
		int ans[100];
		for (size_t i = 0; i < w; i++)
		{
			ans[i] = 0;
			bool flag = false;
			for (size_t j = 0; j < h; j++)
			{
				if (n <= wek[sort[j]][i])
				{
					ans[i] = n * hotel[sort[j]];
					flag = true;
					break;
				}
				/*else
				{
					num = 0;
					ans[i] += num * hotel[sort[j]];
				}
				if ( num == 0 )
				{
					break;
				}*/
			}
			if (flag==false)
			{
				ans[i] = -1;
			}
		}

		int min = sorttt(ans, w);
		if (b>=min && min>=0)
		{
			cout << min << endl;
		}
		else
		{
			cout << "stay home" << endl;
		}

	}
}
