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
string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool ssort(int a1, int a2)
{
	return (a2 < a1);
}
//
int main()
{
	int tc;
	cin >> tc;
	for (size_t q = 1; q <= tc; q++)
	{
		int arr[28] = { 0 };
		string str;
		cin >> str;
		for (size_t i = 0; i < str.length(); i++)
		{
			for (size_t j = 0; j < al.length(); j++)
			{
				if (str[i]==al[j])
				{
					arr[j]++;
					break;
				}
			}
		}
		sort(arr, arr + 28,ssort);
		int big = str.length();
		llu number = 1;
		for (size_t i = 2; i <= big; i++)
		{
			number *= i;
			//number /= i + 1;
		}
		for (size_t i = 0; i < 28; i++)
		{
			if (arr[i]>1)
			{
				for (size_t j = 0; j < arr[i]; j++)
				{
					number /= j + 1;
				}
			}
			else
			{
				break;
			}
		}
		cout << "Data set " << q << ": " << number << endl;
	}
}
