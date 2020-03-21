#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int a, b;
	while (cin >>a>>b)
	{
		int counter = 0,temp=0;
		while (a >= b)
		{
			a -= b;
			counter++;
			temp += b;
			a++;
		}
		temp += a % b;
		cout << temp << endl;
	}
}
