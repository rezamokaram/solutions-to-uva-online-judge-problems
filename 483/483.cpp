#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

/*void sort(int list[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size-1; j++)
		{
			if (list[j]>list[j+1])
			{
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}*/

int main()
{
	string a;
	while (getline(cin,a))
	{
		int len = a.length();
		for (size_t i = 0; i < len; i++)
		{
			if (a[i]==' ')
			{
				
				for (int j = i - 1; 1>0 ; j--)
				{
					if (j<0)
					{
						break;
					}
					if (a[j] == ' ')
					{
						break;
					}
					cout << a[j];
				}
				cout << " ";
			}
			else if (i == len-1)
			{
				for (int j = i ; 1>0 ; j--)
				{
					if (j < 0)
					{
						break;
					}
					if (a[j] == ' ')
					{
						break;
					}
					cout << a[j];
				}
			}
		}
		cout << endl;
	}
}
