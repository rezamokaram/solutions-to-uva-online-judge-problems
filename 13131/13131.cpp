#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		llu n, k;
		cin >> n >> k;
		llu na = 0;
		for (llu i = 1; i <= sqrt(n); i++)
		{
			if (n%i==0)
			{
				if (i%k)
				{
					na += i;
				}
				if ((n/i)!=i)
				{
					
					if ((n/i)%k)
					{
						na += n / i;
					}
				}
			}
		}
		cout << na << endl;
	}
}
