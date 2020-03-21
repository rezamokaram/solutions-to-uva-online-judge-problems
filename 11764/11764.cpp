#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int numb1,numb2,sum1=0,sum2=0;
		cin >> numb1;
		for (size_t j = 0; j < k-1; j++)
		{
			cin >> numb2;
			if (numb2>numb1)
			{
				sum1++;
			}
			else if (numb1>numb2)
			{
				sum2++;
			}
			numb1 = numb2;
		}
		cout << "Case " << i + 1 << ": " << sum1 << " " << sum2 << "\n";
	}
	system("pause>A");
}
