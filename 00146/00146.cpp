#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	string a;
	while (getline(cin,a))
	{
		if (a=="#")
		{
			break;
		}

		if (!next_permutation(a.begin(),a.end()))
		{
			cout << "No Successor" << endl;
		}
		else
		{
			//next_permutation(a.begin(), a.end());
			cout << a << endl;
		}
	}
}
