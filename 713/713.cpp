#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;


int main()
{
	int tc;
	cin >> tc;
	for (size_t z = 0; z < tc; z++)
	{
		string a, b;
		cin >> a >> b;
		if (a.length()<b.length())
		{
			string temp = a;
			a = b;
			b = temp;
		}
		int sum = 0;
		bool f = false;
		for (size_t i = 0; i < a.length(); i++)
		{
			sum += a[i] - '0';
			if (i<b.length())
			{
				sum += b[i] - '0';
			}
			if (f==false && sum%10!=0)
			{
				cout << sum % 10;
				f = true;
			}
			else if (f)
			{
				cout << sum % 10;
				f = true;
			}
			sum /= 10;
		}
		if (sum>0)
		{
			while (sum>0)
			{
				cout << sum % 10;
				sum /= 10;
			}
		}
		cout << endl;
	}
}
/*
char a[300], b[300];
		cin >> a >> b;
		int sizea, sizeb;
		for (sizea = 0; a[sizea]; sizea++);
		for (sizeb = 0; b[sizeb]; sizeb++);
		char na[300], nb[300];
		int ind = 0;
		for (int i = sizea; i >= 0; i--)
		{
			na[ind] = a[i];
			ind++;
		}
		na[ind] = '\0';
		ind = 0;
		for (int i = sizeb; i >= 0; i--)
		{
			nb[ind] = b[i];
			ind++;
		}
		nb[ind] = '\0';
		int sum = 0;
*/
