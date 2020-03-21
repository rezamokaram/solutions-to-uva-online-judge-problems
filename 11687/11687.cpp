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
	string str;
	while (cin >> str && str!="END")
	{
		if (str=="1")
		{
			cout << "1" << endl;
			continue;
		}
		else if (str.length()==1)
		{
			cout << "2" << endl;
			continue;
		}
		int len = str.length();
		int count = 1;
		while (len>1)
		{
			int i = 0;
			while (len>0)
			{
				len /= 10;
				i++;
			}
			len = i;
			count++;
		}
		cout << count + 1 << endl;
	}
}
