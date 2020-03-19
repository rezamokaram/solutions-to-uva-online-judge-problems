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
bool pali(string a, int istart, int iend)
{
	while (istart<iend)
	{
		if (a[istart] != a[iend])
		{
			return false;
		}
		istart++;
		iend--;
	}
	return true;
}
//
string str_crop(string a, int is, int ie)
{
	string nstr;
	for (size_t i = is; i <= ie; i++)
	{
		nstr += a[i];
	}
	return nstr;
}
//
string al = "abcdefghijklmnopqrstuvwxyz";
int main()
{
	string a;
	while (cin >> a)
	{
		int arr[28] = { 0 };
		for (size_t i = 0; i < a.length(); i++)
		{
			for (size_t j = 0; j < al.length(); j++)
			{
				if (a[i]==al[j])
				{
					arr[j]++;
					break;
				}
			}
		}
		int sum = 0;
		for (size_t i = 0; i < al.length(); i++)
		{
			if (arr[i]>0)
			{
				sum++;
			}
		}
		vector<string>list;
		for (size_t i = 0; i < a.length() - 1; i++)
		{
			for (size_t j = i+1; j < a.length(); j++)
			{
				if (pali(a,i,j))
				{
					bool f = true;
					string nstr = str_crop(a, i, j);
					for (size_t z = 0; z < list.size(); z++)
					{
						if (nstr==list[z])
						{
							f = false;
							break;
						}
					}
					if (f)
					{
						sum++;
						list.push_back(nstr);
					}
				}
			}
		}
		cout << "The string '" << a << "' contains " << sum << " palindromes." << endl;
	}
}
