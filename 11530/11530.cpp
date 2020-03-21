#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a[50] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
	string str;
	int tc;
	cin >> tc;
	cin.ignore();
	for (int j=1;j<=tc;j++)
	{
		getline(cin, str);
		int sum = 0,n=str.length();
		for (size_t i = 0; i < n; i++)
		{
			if (str[i]==' ')
			{
				sum++;
			}
			else
			{
				sum += a[str[i] - 'a'];
			}
		}
		cout << "Case #" << j << ": " << sum << endl;
	}
}
