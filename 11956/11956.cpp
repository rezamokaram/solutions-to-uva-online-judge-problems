#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
void out(int number)
{
	int d = number / 16, y = number % 16;
	if (d < 10)
	{
		cout << d;
	}
	else
	{
		char a = 'A' + (d - 10);
		cout << a;
	}
	if (y < 10)
	{
		cout << y;
	}
	else
	{
		char a = 'A' + (y - 10);
		cout << a;
	}
}
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	int cs = 0;
	while (tc--)
	{
		string line;
		getline(cin, line);
		int arr[100] = { 0 };
		int pointer = 0;
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line[i]=='>')
			{
				pointer++;
				if (pointer==100)
					pointer = 0;
			}
			else if (line[i] == '<')
			{
				pointer--;
				if (pointer<0)
					pointer = 99;
			}
			else if (line[i] == '-')
			{
				arr[pointer]--;
				if (arr[pointer] == -1)
					arr[pointer] = 255;
			}
			else if (line[i] == '+')
			{
				arr[pointer]++;
				if (arr[pointer] >= 256)
					arr[pointer] = 0;
			}
		}
		cout << "Case " << ++cs << ":";
		for (size_t i = 0; i < 100; i++)
		{
			cout << " ";
			out(arr[i]);
		}
		cout << endl;
	}
}
