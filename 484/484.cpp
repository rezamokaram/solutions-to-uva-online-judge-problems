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
	long long int a[10000],b[10000],c[10000];
	ll i;
	for (i = 0; cin >> a[i]; i++);
	int size = 0;
	for (size_t j = 0; j < i; j++)
	{
		bool flag = true;
		for (size_t z = 0; z < size; z++)
		{
			if (b[z]==a[j])
			{
				flag = false;
				break;
			}
		}
		if (flag==false)
		{
			continue;
		}
		else
		{
			b[size] = a[j];
			int counter = 0;
			for (size_t z = 0; z < i; z++)
			{
				if (b[size]==a[z])
				{
					counter++;
				}
			}
			c[size] = counter;
			size++;
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << b[i] << " " << c[i] << endl;
	}
}
