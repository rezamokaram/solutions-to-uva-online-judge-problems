#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
vector<int>aa;
vector<int>bb;
string a, b;
//
void f()
{
	for (int i = a.length()-1; i >= 0; i--)
	{
		if (a[i]>='0' && a[i]<='9')
		{
			aa.push_back(a[i] - '0');
		}
		else
		{
			aa.push_back(a[i] - 'A' + 10);
		}
	}
	for (int i = b.length()-1; i >= 0; i--)
	{
		if (b[i] >= '0' && b[i] <= '9')
		{
			bb.push_back(b[i] - '0');
		}
		else
		{
			bb.push_back(b[i] - 'A' + 10);
		}
	}
}
//
vector<llu>baseb;
int search(int x)
{
	for (int i = 0; i < baseb.size(); i++)
	{
		if (x==baseb[i])
		{
			return i;
		}
	}
	return -1;
}
//
int best()
{
	int max = 0;
	for (size_t i = 0; i < bb.size(); i++)
	{
		if (bb[i]>max)
		{
			max = bb[i];
		}
	}
	return max + 1;
}
//
int bbest()
{
	int max = 0;
	for (size_t i = 0; i < aa.size(); i++)
	{
		if (aa[i] > max)
		{
			max = aa[i];
		}
	}
	return max + 1;
}
int main()
{
	while (cin >> a >> b)
	{
		aa.clear();
		bb.clear();
		baseb.clear();
		f();
		if (a=="0" && b=="0")
		{
			cout << "0 (base 2) = 0 (base 2)" << endl;
			continue;
		}
		else if (a == b)
		{
			cout << a << " (base " << bbest() << ") = " << b << " (base " << best() << ")" << endl;
			continue;
		}
		
		int bm = best();
		for (double i = bm; i < 37; i++)
		{
			ll sum = 0;
			for (size_t j = 0; j < bb.size(); j++)
			{
				sum += pow(i, j)*bb[j];
			}
			baseb.push_back(sum);
		}
		//
		int firstbase=0, secondbase;
		for (double i = bbest(); i < 37; i++)
		{
			ll sum = 0;
			for (size_t j = 0; j < aa.size(); j++)
			{
				sum += pow(i, j)*aa[j];
			}
			secondbase = search(sum);
			if (secondbase != -1)
			{
				secondbase += bm;
				firstbase = i;
				break;
			}
		}
		//output
		if (firstbase)
		{
			cout << a << " (base " << firstbase << ") = " << b << " (base " << secondbase << ")" << endl;
		}
		else
		{
			cout << a << " is not equal to " << b << " in any base 2..36" << endl;
		}
	}
}
