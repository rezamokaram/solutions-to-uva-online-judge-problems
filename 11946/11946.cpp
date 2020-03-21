#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
string n = "OIZEASGTBP";
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string a;
		while (getline(cin, a))
		{


			for (size_t i = 0; i < a.length(); i++)
			{
				if (a[i] >= '0' && a[i] <= '9')
				{
					cout << n[a[i] - '0'];
				}
				else
				{
					cout << a[i];
				}
			}
			cout << endl;
		}
	}
}
