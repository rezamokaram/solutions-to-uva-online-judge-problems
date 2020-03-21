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
	cin.ignore();
	string a;
	for (size_t z = 0; z < tc; z++)
	{
		string temp;
		getline(cin, temp);
		a += temp;
	}
	int arr[28] = { 0 };
	string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (size_t i = 0; i < a.length(); i++)
	{
		for (size_t j = 0; j < al.length(); j++)
		{
			if (a[i]==al[j] || a[i]==al[j]+32)
			{
				arr[j]++;
				break;
			}
		}
	}
	for (size_t i = 0; i < al.length(); i++)
	{
		for (size_t j = 0; j < al.length()-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				char temp1 = al[j];
				al[j] = al[j + 1];
				al[j + 1] = temp1;
			}
			if (arr[j]==arr[j+1] && al[j]<al[j+1])
			{
				char temp1 = al[j];
				al[j] = al[j + 1];
				al[j + 1] = temp1;
			}
		}
	}
	for (int i = al.length()-1; i >= 0; i--)
	{
		if (arr[i]==0)
		{
			break;
		}
		cout << al[i] << " " << arr[i] << endl;
	}
}
