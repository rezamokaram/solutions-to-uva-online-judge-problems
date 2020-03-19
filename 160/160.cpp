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
//
vector<int>primes;
void f()
{
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	primes.push_back(13);
	primes.push_back(17);
	primes.push_back(19);
	primes.push_back(23);
	primes.push_back(29);
	primes.push_back(31);
	primes.push_back(37);
	primes.push_back(41);
	primes.push_back(43);
	primes.push_back(47);
	primes.push_back(53);
	primes.push_back(59);
	primes.push_back(61);
	primes.push_back(67);
	primes.push_back(71);
	primes.push_back(73);
	primes.push_back(79);
	primes.push_back(83);
	primes.push_back(89);
	primes.push_back(97);
}
int main()
{
	f();
	int n;
	while (cin >> n && n)
	{
		
		int numbers[25] = { 0 };
		for (size_t i = 2; i <= n; i++)
		{
			int digit = i;
			for (size_t j = 0; j < primes.size(); j++)
			{
				while (digit%primes[j]==0 && digit>0)
				{
					digit /= primes[j];
					numbers[j]++;
				}
				if (digit<=1)
				{
					break;
				}
			}
		}
		//output
		if (n<100)
		{
			cout << " ";
		}
		if (n<10)
		{
			cout << " ";
		}
		cout << n;
		cout << "!";
		cout << " =";
		int my_len = 0;
		for (size_t i = 0; i < 25; i++)
		{
			if (numbers[i]!=0)
			{
				my_len = i+1;
			}
		}
		int end = 0;
		for (size_t i = 0; i < my_len; i++)
		{
			if (end == 15)
			{
				cout << endl << "      ";
			}
			if (numbers[i]<100)
			{
				cout << " ";
			}
			if (numbers[i]<10)
			{
				cout << " ";
			}
			if (numbers[i]==0)
			{
				cout << " ";
			}
			else
			{
				cout << numbers[i];
			}
			end++;
			
		}
		cout << endl;
	}
}
