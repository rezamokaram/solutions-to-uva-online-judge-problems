#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		long long int k,sum=0;
		cin >> k;
		for (size_t j = 0; j < k; j++)
		{
			long long int a, b, c;
			cin >> a >> b >> c;
			sum += a*c;
		}
		cout << sum << endl;
	}
	system("pause>A");
}
