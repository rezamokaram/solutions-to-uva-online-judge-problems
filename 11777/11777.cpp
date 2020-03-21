#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < 4; j++)
		{
			int a;
			cin >> a;
			sum += a;
		}
		int cl[3];
		for (size_t j = 0; j < 3; j++)
		{
			cin >> cl[j];
		}
		sort(cl, cl + 3);
		sum += (cl[1] + cl[2])/2;
		if (sum>=90)
		{
			cout << "Case " << i + 1 << ": A" << endl;
		}
		else if (sum >= 80)
		{
			cout << "Case " << i + 1 << ": B" << endl;
		}
		else if (sum >= 70)
		{
			cout << "Case " << i + 1 << ": C" << endl;
		}
		else if (sum >= 60)
		{
			cout << "Case " << i + 1 << ": D" << endl;
		}
		else if (sum < 60)
		{
			cout << "Case " << i + 1 << ": F" << endl;
		}
	}
}
