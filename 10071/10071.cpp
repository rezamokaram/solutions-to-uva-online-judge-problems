#include <iostream>
using namespace std;
int main()
{
	double t, v;
	while (cin >> v >> t)
	{
		if (t > 0)
		{
			double temp = ((v / t) * (2 * t)*(2 * t)) / 2;
			cout << temp <<"\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
	system("pause>A");
}
