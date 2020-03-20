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
void ssum(string a, string b, char arr[])
{
	if (b.length() > a.length())
	{
		string d;
		d = a;
		a = b;
		b = d;
	}
	int sum = 0;
	int counter = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		sum += a[i] - '0';
		if (counter < b.length())
		{
			sum += b[b.length() - counter - 1] - '0';
		}
		arr[counter] = '0' + (sum % 10);
		counter++;
		sum /= 10;
	}
	while (sum > 0)
	{
		arr[counter] = '0' + sum % 10;
		sum /= 10;
		counter++;
	}
	arr[counter] = '\0';
	char arr3[110];
	int zd = 0;
	for (int i = counter - 1; i >= 0; i--)
	{
		arr3[zd] = arr[i];
		zd++;
	}
	arr3[counter] = '\0';
	for (size_t i = 0; i < counter; i++)
	{
		arr[i] = arr3[i];
	}
}
//
int main()
{
	string a;
	bool f = false;
	string d;
	while (getline(cin,a))
	{
		if (a=="0")
		{
			break;
		}
		if (!f)
		{
			char arr[1000] = "0\0";
			d = arr;
			ssum(a, d, arr);
			d = arr;
			f = true;
		}
		else
		{
			char arr[1000];
			ssum(a, d, arr);
			d = arr;
		}
	}
	cout << d << endl;
}
