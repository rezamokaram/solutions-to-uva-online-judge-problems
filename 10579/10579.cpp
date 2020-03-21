#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

void rev(char list[],int size)
{

	char temp[1010];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = list[size - 1 - i];
	}
	temp[size] = '\0';
	for (size_t i = 0; i < size; i++)
	{

		list[i] = temp[i];
	}
}

int main()
{
	int a;
	while (cin >> a)
	{
		int f1[1010] = { 1 };
		int f2[1010] = { 1 };
		int f3[1010];
		int size = 1;
		int sum = 0;
		int nsize = 0;
		for (size_t i = 0; i < a-2; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				sum += f2[j];
				if (f1[j]>=0 && f1[j]<=9)
				{
					sum += f1[j];
				}
				f3[nsize] = sum % 10;
				sum /= 10;
				nsize++;
			}
			if (sum>0)
			{
				while (sum>0)
				{
					f3[nsize] = sum % 10;
					sum /= 10;
					nsize++;
				}
			}
			if (i == a-3)
			{
				for (int i = nsize-1; i >= 0; i--)
				{
					cout << f3[i];
				}
				cout << endl;
				break;
			}
			else
			{
				for (size_t i = 0; i < size; i++)
				{
					f1[i] = f2[i];
				}
				for (size_t i = 0; i < nsize; i++)
				{
					f2[i] = f3[i];
				}
				size = nsize;
				nsize = 0;
			}
		}
	}
}
