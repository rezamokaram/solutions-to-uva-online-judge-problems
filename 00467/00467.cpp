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
int gcd(int a, int b) { return(b == 0) ? a : gcd(b, a%b); }
int lcm(int a, int b) { return(a*b / gcd(a, b)); }
//
vector<int>num;
int addnums(string str)
{
	int x = 0, min = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			if (x)
			{
				num.push_back(x);
				if (x * 2 > min)
				{
					min = x * 2;
				}
				x = 0;
			}
		}
		else
		{
			x *= 10;
			x += str[i] - '0';
			if (i == str.length() - 1)
			{
				if (x)
				{
					num.push_back(x);
					if (x * 2 > min)
					{
						min = x * 2;
					}
				}
				x = 0;
			}
		}
	}
	return min;
}
int main()
{
	int tc = 0;
	string nums;
	while (getline(cin, nums))
	{
		num.clear();
		int min = addnums(nums);
		int i;
		sort(num.begin(), num.end());
		for (i = num[0]; i < 3601; i++)
		{
			bool f = 1;
			for (size_t j = 0; j < num.size(); j++)
			{
				if ((i / num[j]) % 2 == 1 || ((i + 5) / num[j]) % 2 == 1)
				{
					f = 0;
					break;
				}
			}
			if (f)
				break;
		}
		tc++;
		int minn = i / 60;
		int sec = i % 60;
		if (i > 3600)
		{
			cout << "Set " << tc << " is unable to synch after one hour." << endl;
		}
		else
		{
			cout << "Set " << tc << " synchs again at " << minn << " minute(s) and " << sec << " second(s) after all turning green." << endl;
		}
		//cout << lcm(35, lcm(25, 30))/60;
	}
}
