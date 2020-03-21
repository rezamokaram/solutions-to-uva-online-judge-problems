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
vector<ll>ans;
int main()
{
	ans.push_back(1);
	ans.push_back(1);
	ans.push_back(2);
	ans.push_back(6);
	ans.push_back(24);
	ans.push_back(120);
	ans.push_back(720);
	ans.push_back(5040);
	ans.push_back(40320);
	ans.push_back(362880);
	ans.push_back(3628800);
	ans.push_back(39916800);
	ans.push_back(479001600);
	ans.push_back(6227020800);
	ll a;
	while (cin >> a)
	{
		if (a<0)
		{
			a *= -1;
			if (a%2==0)
			{
				
				cout << "Underflow!" << endl;
			}
			else
			{
				cout << "Overflow!" << endl;
			}
			
		}
		else if (a<8)
		{
			cout << "Underflow!" << endl;
		}
		else if(a>13)
		{
			cout << "Overflow!" << endl;
		}
		else
		{
			cout << ans[a] << endl;
		}
	}
}
