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
	int ans, left = 0, right = 11;
	while (cin >> n && n)
	{
		string how,h;
		cin >> how >> h;
		how += " ";
		how += h;
		//cout << n << endl << how << endl;
		if (how=="right on")
		{
			ans = n;
			if (ans>=right || ans<=left)
			{
				cout << "Stan is dishonest" << endl;
			}
			else
			{
				cout << "Stan may be honest" << endl;
			}
			//cout << endl;
			left = 0;
			right = 11;
		}
		else if (how=="too low")
		{
			if (n>left)
			{
				left = n;
			}
		}
		else
		{
			if (n < right)
			{
				right = n;
			}
		}
	}
}
