#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		double k;
		cin >> k;
		double sum = 0;
		double arr[10000];
		for (size_t j = 0; j < k; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}
		sum = sum / k;
		double d = 0;
		for (size_t j = 0; j < k; j++)
		{
			if (arr[j]>sum)
			{
				d++;
			}
		}
		double av = (d / k) * 100;
		cout << fixed << setprecision(3) << av << "%" << "\n";
	}
	system("pause>A");
}
