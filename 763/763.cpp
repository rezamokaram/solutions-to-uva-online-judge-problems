#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
string myReverse(string str)
{
	string nstr;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		nstr += str[i];
	}
	return nstr;
}
//
int main()
{
	string aa, bb;
	bool first = 0;
	while (cin >> aa >> bb)
	{
		if (first)
		{
			cout << endl;
		}
		first = 1;
		//
		int max = aa.length();
		if (bb.length()>max)
		{
			max = bb.length();
		}
		aa = myReverse(aa);
		bb = myReverse(bb);
		//
		vector<int>fib;
		for (size_t i = 0; i < max + 2; i++)
		{
			int number = 0;
			if (i<aa.length())
			{
				if (aa[i]=='1')
				{
					number++;
				}
			}
			if (i < bb.length())
			{
				if (bb[i] == '1')
				{
					number++;
				}
			}
			//
			fib.push_back(number);
		}
		//
		bool sec = 0;
		do
		{
			fib.push_back(0);
			fib.push_back(0);
			sec = 0;
			for (int i = 0; i < fib.size() - 2; i++)
			{
				if (fib[i + 1] > 0 && fib[i] > 0)
				{
					fib[i]--;
					fib[i + 1]--;
					fib[i + 2]++;
					sec = 1;
				}
				if (fib[i] > 1)
				{
					sec = 1;
					fib[i] -= 2;
					if (i==0)
					{
						fib[1]++;
					}
					else if (i==1)
					{
						fib[0]++;
						fib[2]++;
					}
					else
					{
						fib[i + 1]++;
						fib[i - 2]++;
					}
				}
			}
		} while (sec);
		while (fib[fib.size()-1]==0 && fib.size()>1)
		{
			fib.pop_back();
		}
		//
		for (int i = fib.size()-1; i >= 0; i--)
		{
			cout << fib[i];
		}
		cout << endl;
	}
}
