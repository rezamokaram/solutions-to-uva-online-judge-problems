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
bool sign_ch(char main, char nsign, char newch)
{
	if (main == 'x' && nsign == '-')return true;
	else if (main == 'z' && newch == 'z' && nsign == '+')return true;
	else if (main == 'y' && newch == 'y' && nsign == '+')return true;
	return false;
}
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		char main = 'x';
		int sign = 1;
		for (size_t i = 0; i < n-1; i++)
		{
			char nsign, newch;
			cin >> nsign >> newch;
			if (nsign == 'N')continue;
			if (sign_ch(main, nsign, newch))sign *= -1;
			if (main == 'x')main = newch;
			else if (main =='y' && newch == 'y')main = 'x';
			else if (main =='z' && newch == 'z')main = 'x';
		}
		char s = '+';
		if (sign == -1)s = '-';
		cout << s << main << endl;
	}
}
