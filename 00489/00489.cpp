#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int strchek(string a, char list[])
{
	list[0] = a[0];
	int size = 1;
	for (size_t i = 1; i < a.length(); i++)
	{
		bool flag = true;
		for (size_t j = 0; j < size; j++)
		{
			if (a[i]==list[j])
			{
				flag = false;
				break;
			}
		}
		if (flag==true)
		{
			list[size] = a[i];
			size++;
		}
	}
	return size;
}

int main()
{
	int a;
	while (cin >> a)
	{
		if (a==-1)
		{
			break;
		}
		string str, str2;
		cin >> str >> str2;
		bool flag = true;
		int check = 0;
		int chekl = 0;
		char character[100];
		char character2[100];
		int size = strchek(str, character);
		int size2= strchek(str2, character2);
		for (size_t i = 0; i < size2; i++)
		{
			if (chekl>=7)
			{
				break;
			}
			if (check==size)
			{
				break;
			}
			bool f = false;
			for (size_t j = 0; j < size; j++)
			{
				if (character2[i]==character[j])
				{
					check++;
					character[j] = ',';
					f = true;
					break;
				}
			}
			if (f==false)
			{
				chekl++;
			}
		}
		if (check==size)
		{
			cout << "Round " << a << endl << "You win." << endl;
		}
		else if (chekl<7 && check<size)
		{
			
			cout << "Round " << a << endl << "You chickened out." << endl;
		}
		else
		{
			cout << "Round " << a << endl << "You lose." << endl;
		}
	}
}
