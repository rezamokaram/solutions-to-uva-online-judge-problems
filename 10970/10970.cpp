#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a <= 1 && b <= 1 || a == 0 || b == 0)
		{
			cout << 0 << endl;
			continue;
		}
		if (b < a)
		{
			int temp = b;
			b = a;
			a = temp;
		}
		int sum2 = (a - 1) + (a * (b - 1));
		cout << sum2 << endl;
	}
}
