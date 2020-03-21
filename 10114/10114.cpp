#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main()
{
	double brow, cost;
	int numdper,month;
	while (cin >> month >> brow >> cost >> numdper)
	{
		if (month<0)
		{
			break;
		}
		
		double darsad[101];
		for (size_t i = 0; i < numdper; i++)
		{
			int m;
			double z;
			cin >> m >> z;
			for (size_t j = m; j < 101; j++)
			{
				darsad[j] = z;
			}
		}


		double money = cost;
		int i=0;
		double ncost = (cost + brow) * (1.0 - darsad[i]);
		double mp= (cost / month);


		for (i = 0; money > ncost;i++)
		{
			ncost *= (1.0 - darsad[i+1]);
			money -= mp;
		}


		if (i==1)
		{
			cout << i << " month\n";
		}
		else
		{
			cout << i << " months\n";
		}
		
	}
}
