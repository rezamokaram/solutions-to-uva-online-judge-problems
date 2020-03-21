#include <iostream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a, b, counter = 0;
	string  c;
	char t1, t2;
	while (cin >> a >> t1 >> b >> t2 >> c)
	{
		if (c == "?")
			continue;
		if (t1 == '+')
		{
			if (a + b == stoi(c))
				counter++;
		}
		else if (t1 == '-')
		{
			if (a - b == stoi(c))
				counter++;
		}

	}
	cout << counter << endl;
}
