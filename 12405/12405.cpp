#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;



int main()
{
	char a[200],b[200];
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int len;
		cin >> len;
		cin >> a;
		int counter = 0;
		for (size_t j = 0; j < len;)
		{
			if (a[j]=='#')
			{
				j++;
			}
			else
			{
				counter++;
				j += 3;
			}
		}
		cout << "Case " << i + 1 << ": " << counter << endl;
	}
}
