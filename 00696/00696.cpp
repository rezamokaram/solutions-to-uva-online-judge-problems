#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	long long int a, b;
	while (cin >>a >>b)
	{
		if (a==0 && b==0)
		{
			break;
		}
		if (a==1||b==1)
		{
			cout << a * b << " knights may be placed on a " << a << " row " << b << " column board." << endl;
		}
		else if (a==2 || b==2)
		{
			bool flag = true;
			if (b==2)
			{
				flag = false;
				b = a;
				a = 2;
			}
			long long int temp = b,sum=0;
			for (size_t i = 0; i < b; i++)
			{
				if (i%4==0 || i%4==1)
				{
					sum += 2;
				}
				else
				{
					continue;
				}
			
			}
			if (flag == true)
			{
				cout << sum << " knights may be placed on a " << a << " row " << b << " column board." << endl;
			}
			else
			{
				cout << sum << " knights may be placed on a " << b << " row " << a << " column board." << endl;
			}
		}
		else 
		{
			if (a*b%2==1)
			{
				cout << ((a * b)/2)+1 << " knights may be placed on a " << a << " row " << b << " column board." << endl;
			}
			else
			{
				cout << (a * b)/2 << " knights may be placed on a " << a << " row " << b << " column board." << endl;
			}
		}
	}
}
