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

llu funcf(int number)
{
	double a = number;
	a /= 2;
	double b = (2 * 1) + (number - 1) * 2;
	b *= a;
	llu sum = b;
	return sum;
}
//
llu funcz(int number)
{
	double a = number;
	a /= 2;
	double b = (2 * 2) + (number - 1) * 2;
	b *= a;
	llu sum = b;
	return sum;
}
//
vector<llu>ans;
void f()
{
	ans.push_back(0);
	ans.push_back(0);
	ans.push_back(0);
	ans.push_back(0);
	llu counter = 0;
	for (size_t i = 4; i <= 1000000; i++)
	{
		if (i % 2 == 0)
		{
			counter += funcf(i - ((i / 2) + 1));
		}
		else
		{
			llu d = (((i + 1) / 2) + 1);
			counter += funcz(i - d);
		}
		ans.push_back(counter);
	}
	//cout << counter << endl;

}
int main()
{
	int number;
	f();
	while (cin >> number && number > 2)
	{
		cout << ans[number] << endl;
	}
}
