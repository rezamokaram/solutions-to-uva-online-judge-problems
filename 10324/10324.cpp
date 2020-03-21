#include<iostream>
using namespace std;
int main()
{
	char a[1000000];
	for (int z=1;cin >>a;z++)
	{
		int n;
		cin >> n;
		cout << "Case " << z << ":" << "\n";
		for (size_t i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (x > y)
			{
				int r = x;
				x = y;
				y = r;
			}
			int flag = 0;
			for (size_t j = x; j < y; j++)
			{
				if (a[j] != a[j + 1])
				{
					flag = 1;
					break;
				}
			}
			if (flag==0)
			{
				cout << "Yes" << "\n";
			}
			else
			{
				cout << "No" << "\n";
			}
		}
	}
	system("pause>A");
}
