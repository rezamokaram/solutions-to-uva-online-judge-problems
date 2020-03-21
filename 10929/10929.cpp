#include <iostream>
#include <string>

using namespace std;

int main()
{
	string integers = "0123456789";
	string str;
	while (cin >> str)
	{
		if (str=="0")
		{
			break;
		}
		int len = str.length();
		long long int sum = 0;
		for (int i = len - 1; i >= 0; i-=2)
		{
			for (int j = 0; j < 10; j++)
			{
				if (str[i]==integers[j])
				{
					sum += j;
					break;
				}
			}
		}
		int sum2 = 0;
		for (int i = len - 2; i >= 0; i -= 2)
		{
			for (int j = 0; j < 10; j++)
			{
				if (str[i] == integers[j])
				{
					sum2 += j;
					break;
				}
			}
		}
		sum -= sum2;
		if (sum<0)
		{
			sum *= -1;
		}
		if (sum%11==0)
		{
			cout << str << " is a multiple of 11." << endl;
		}
		else
		{
			cout << str << " is not a multiple of 11." << endl;
		}
	}
}
