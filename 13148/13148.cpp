#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	long long int a,temp;
	while (cin >> a)
	{
		if (a==0)
		{
			break;
		}
		if (a == 1)
		{
			cout << "Special" << endl;
			continue;
		}
		temp = sqrt(sqrt(a));
		int list[100000],i;
		for (i=2;a>1;i++)
		{
			if (i > temp)
			{
				break;
			}
			int counter = 0;
			while (a%i == 0)
			{
				
				a /= i;
				counter++;
				if (a==1)
				{
					break;
				}
			}
			list[i-2] = counter;
		}
		bool flag = false;
		for (size_t j = 0; j < i-2; j++)
		{
			if (list[j]%6==0 && list[j]!=0)
			{
				flag = true;
				break;
			}
		}
		if (flag==true && a==1)
		{
			cout << "Special" << endl;
		}
		else
		{
			cout << "Ordinary" << endl;
		}
	}
}
