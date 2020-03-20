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
	int d, o, f;
	int tc = 0;
	while (cin >> d >> o >> f && d && o && f)
	{
		tc++;
		vector<int>p(d);
		vector<bool>sw(d);
		for (size_t i = 0; i < d; i++)
		{
			int temp;
			cin >> temp;
			p[i] = temp;
			sw[i] = 0;
		}
		int max = 0, sum = 0;
		for (size_t i = 0; i < o; i++)
		{
			int index;
			cin >> index;
			if (sw[index-1])
			{
				sw[index - 1] = 0;
				sum -= p[index - 1];
			}
			else//0
			{
				sw[index - 1] = 1;
				sum += p[index - 1];
			}
			if (sum>max)
			{
				max = sum;
			}
		}
		cout << "Sequence " << tc << endl;
		if (max>f)
		{
			cout << "Fuse was blown." << endl;
		}
		else
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max << " amperes." << endl;
		}
		cout << endl;
	}
}
