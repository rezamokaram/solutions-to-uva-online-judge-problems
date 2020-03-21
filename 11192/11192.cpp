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
int main()
{
	int n;
	while (cin >> n && n)
	{
		
		string str;
		cin >> str;
		n = str.length() / n;
		int indexs = 0;
		int seek = 0;
		for (size_t i = 1; i <= str.length(); i++)
		{
			if (i%n==0 && i != 0 || i==str.length())
			{
				for (int j = i-1; j >= indexs; j--)
				{
					cout << str[j];
				}
				indexs += n;
			}
		}
		cout << endl;
	}
}
