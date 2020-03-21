#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int index_min(int list[],int start, int size)
{
	int min = list[start];
	int index = start;
	for (size_t i = start; i < size; i++)
	{
		if (min>list[i])
		{
			min = list[i];
			index = i;
		}
	}
	return index;
}
//

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		//input
		int h = a, l = b;
		int arr[300][300];
		int counter = 0;
		for (size_t i = 0; i < a; i++)
		{
			for (size_t j = 0; j < b; j++)
			{
				cin >> arr[i][j];
			}
		}
		//sort_by_command
		//row
		for (size_t i = 0; i < b; i++)
		{
			int indexmin = index_min(arr[0], i, b);
			if (indexmin!=i)
			{
				for (size_t d = 0; d < a; d++)
				{
					swap(arr[d][i], arr[d][indexmin]);
				}
				counter++;
			}
		}
		//cal
		for (size_t i = 0; i < a; i++)
		{
			int list[10000];
			for (size_t j = 0; j < a; j++)
			{
				list[j] = arr[j][0];
			}
			int indexmin = index_min(list, i, a);
			if (indexmin != i)
			{
				for (size_t d = 0; d < b; d++)
				{
					swap(arr[i][d], arr[indexmin][d]);
				}
				counter++;
			}
		}
		//check
		bool f = true;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < l-1; j++)
			{
				if (arr[i][j] > arr[i][j+1])
				{
					f = false;
					break;
				}
			}
			if (!f)
			{
				break;
			}
		}
		for (size_t i = 0; i < h - 1; i++)
		{
			for (size_t j = 0; j < l; j++)
			{
				if (arr[i][j] > arr[i + 1][j])
				{
					f = false;
					break;
				}
			}
			if (!f)
			{
				break;
			}
		}
		//output
		if (!f)
		{
			cout << "*" << endl;
		}
		else
		{
			cout << counter << endl;
		}
	}
}
