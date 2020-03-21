#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool prime(int number)
{
	if (number <= 2)
	{
		return true;
	}
	//bool flag = true;
	for (size_t i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			//flag = false;
			//break;
			return false;
		}
	}
	return true;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		int sum = 0;
		int len = str.length();
		for (size_t i = 0; i < len; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				sum += str[i] - 'a' + 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				sum += str[i] - 'A' + 27;
			}

		}
		if (prime(sum))
		{
			cout << "It is a prime word." << endl;
		}
		else
		{
			cout << "It is not a prime word." << endl;
		}
	}
}
