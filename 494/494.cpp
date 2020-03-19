#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	while (getline(cin,a))
	{
		int counter = 0,t;
		for (t = 0; a[t]; t++);
		for (size_t i = 0; i < t; i++)
		{
			if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
			{
				counter++;
				int j=0;
				for ( j = 0; j < t; j++)
				{
					if (a[i+j] >= 'a' && a[i+j] <= 'z' || a[i+j] >= 'A' && a[i+j] <= 'Z')
					{
						continue;
					}
					else
					{
						break;
					}
				}
				i += j;
			}
		}
		cout << counter << endl;
	}

	system("pause>A");
}
