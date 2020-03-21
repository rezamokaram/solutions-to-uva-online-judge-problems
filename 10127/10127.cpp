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
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
vector<string>l;
vector<string>n;
vector<bool>s;
//
int main()
{
	int num;
	while (cin >> num)
	{
		int x = 0;
		int main = 0;
		do
		{
			main = (main * 10 + 1) % num;
			x++;
		} while (main!=0);
		cout << x << endl;
	}
}
