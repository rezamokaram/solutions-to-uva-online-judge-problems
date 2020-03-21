#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int k,max;
		cin >> k;
		cin >> max;
		for (size_t j = 0; j < k-1; j++)
		{
			int a;
			cin >> a;
			if (a>max)
			{
				max = a;
			}
		}
		cout << "Case " << i + 1 << ": " << max << "\n";
	}
	system("pause>A");
}
