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
	ll a, b;
	for (size_t tc = 1; cin >> a >> b && a>0 && b>0; tc++)
	{
		ll a1 = a;
		int counter = 0;
		for (; a > 1 && a <= b;)
		{
			counter++;
			/*if (a <= 1 || a > b)
			{
				break;
			}*/
			if (a%2==0)
			{
				a /= 2;
			}
			else
			{
				a = 3 * a + 1;
			}
		}
		counter++;
		if (a>b)
		{
			counter--;
		}
		//output
		cout <<"Case "<<tc<<": A = "<<a1<<", limit = "<<b<<", number of terms = "<< counter << endl;
	}
}
