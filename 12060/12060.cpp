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
int bmm(int a, int b)
{
	return (b == 0) ? a : bmm(b, a % b);
}
//
int lennum(int x)
{
	int len = 0;
	for (len = 0; x > 0; len++)
		x /= 10;
	return len;
}
int main()
{
	int tc = 0;
	int n;
	while (cin >> n && n)
	{
		tc++;
		cout << "Case " << tc << ":" << endl;
		vector<int>list;
		int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			list.push_back(temp);
			sum += temp;
		}
		char sine = '+';
		if (sum < 0)
		{
			sum *= -1;
			sine = '-';
		}
		int zrb = sum / n;
		sum %= n;
		if (sum==0)
		{
			if (sine=='-')
			{
				cout << sine << " ";
			}
			cout << zrb;
		}
		else
		{
			int bm = bmm(sum, n);
			sum /= bm;
			n /= bm;
			if (sine=='-')
			{
				cout << "  ";
			}
			int lenz = 0;
			if (zrb!=0)
			{
				lenz = lennum(zrb);
			}
			for (size_t i = 0; i < lenz; i++)
			{
				cout << " ";
			}
			int lens = lennum(sum);
			int lenm = lennum(n);
			int fasele = lenm - lens;
			for (size_t i = 0; i < fasele; i++)
			{
				cout << " ";
			}
			cout << sum << endl;
			//first line ended
			//second line started
			if (sine=='-')
			{
				cout << sine << " ";
			}
			if (zrb!=0)
			{
				cout << zrb;
			}
			for (size_t i = 0; i < lenm; i++)
			{
				cout << "-";
			}
			cout << endl;
			//second line ended
			//yhird line started
			if (sine=='-')
			{
				cout << "  ";
			}
			for (size_t i = 0; i < lenz; i++)
			{
				cout << " ";
			}
			cout << n;
		}
		cout << endl;
	}
}
