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

//
int main()
{
	int a, b, c;
	while (cin >>a>>b>>c)
	{
		if (a==0 && b==0 && c==0 || a == 1 && b == 1 && c == 1)
		{
			cout << "*" << endl;
		}
		else if (a==1 && b==0 && c==0 || a==0 && b==1 && c==1)
		{
			cout << "A" << endl;
		}
		else if (a== 0 && b == 1 && c == 0 || a == 1 && b == 0 && c == 1)
		{
			cout << "B" << endl;
		}
		else //if (a == 0 && b == 1 && c == 0 || a == 1 && b == 0 && c == 1)
		{
			cout << "C" << endl;
		}
	}
}
