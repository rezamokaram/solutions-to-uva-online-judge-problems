#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int len(string str)
{
	int counter;
	for (counter = 0; str[counter]; counter++);
	return counter;
}
int main()
{
	string str1, str2;
	while (cin >> str1>>str2)
	{
		int len1 = len(str1);
		int len2 = len(str2);
		int j = 0;
		for (size_t i = 0; i < len2; i++)
		{
			if (str1[j]==str2[i])
			{
				j++;
			}
			if (j==len1)
			{
				break;
			}
		}
		if (j==len1)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}

	system("pause>A");
}

