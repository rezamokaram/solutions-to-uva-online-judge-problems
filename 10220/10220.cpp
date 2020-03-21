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
	char arr3[11000];
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
	arr[counter] = '\0';
}
//
void zero(string a, int nz, char end[])
{
	for (size_t i = 0; i < a.length(); i++)
	{
		end[i] = a[i];
	}
	for (size_t i = a.length(); i < a.length() + nz; i++)
	{
		end[i] = '0';
	}
	end[nz + a.length()] = '\0';
}
//
void mult(string a, string b, char c[])
{
	llu sum = 0;
	char main[100000] = "0";
	for (size_t i = 0; i < b.length(); i++)
	{
		int digit = b[i] - '0';
		for (size_t j = 0; j < digit; j++)
		{
			char zeroo[10000];
			zero(a, b.length() - i - 1, zeroo);

			string a1 = zeroo;
			/*for (size_t z = 0; z < b.length() - i; z++)
			{
				ddd
					//zone
				a1[z + a.length()] = '0';
			}*/
			string hmain = main;
			ssum(hmain, a1, main);
			//cout << main << endl;
		}
	}
	int size = 0;
	for (size = 0; main[size]; size++);
	for (size_t i = 0; i < size; i++)
	{
		c[i] = main[i];
	}
	c[size] = '\0';
}
//
void itostr(char str[], int number)
{
	//str.clear();
	int d = number;
	int len = 0;
	for (len = 0; d > 0; len++)
	{
		d /= 10;
	}
	char rev[10000];
	for (size_t i = 0; i < len; i++)
	{
		rev[i] = number % 10 + '0';
		number /= 10;
	}
	rev[len] = '\0';
	int index = 0;
	char newc[100000];
	for (int i = len - 1; i >= 0; i--)
	{
		newc[index] = rev[i];
		index++;
	}
	newc[index] = '\0';
	for (size_t i = 0; i < len; i++)
	{
		str[i] = newc[i];
	}
	str[len] = '\0';

}
//
int digitl(int a)
{
	int i;
	if (a == 0)
	{
		return 1;
	}
	for (i = 0; a > 0; i++)
	{
		a /= 10;
	}
	return i;
}
//
vector<string> listans;
//
void f()
{
	listans.push_back("1");
	listans.push_back("1");
	listans.push_back("2");
	string a = "2";
	string b = "3";
	char c[100000];
	for (size_t i = 3; i <= 1000; i++)
	{
		mult(a, b, c);
		a = c;
		listans.push_back(a);
		char s[100000];
		itostr(s, i + 1);
		b = s;
	}
}
int main()
{
	f();
	int number;
	while (cin >> number)
	{
		ll sum = 0;
		for (size_t i = 0; i < listans[number].length(); i++)
		{
			sum += (listans[number][i] - '0');
		}
		cout << sum << endl;
		//cout << number << "!" << endl << listans[number] << endl;
	}
}
