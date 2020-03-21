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
	int nn, nr;
	int ind = 0;
	while (cin >> nn >> nr)
	{
		cin.ignore();
		if (nn==0 && nr==0)
		{
			break;
		}
		if (ind > 0)
		{
			cout << endl;
		}
		ind++;
		string chert;
		for (size_t i = 0; i < nn; i++)
		{
			getline(cin, chert);
		}
		string namebestreq;
		double bestcost = 0;
		int bestnumber = 0;
		for (size_t i = 0; i < nr; i++)
		{
			string name;
			getline(cin, name);
			double price;
			int number;
			cin >> price >> number;
			cin.ignore();
			if (number > bestnumber)
			{
				bestcost = price;
				bestnumber = number;
				namebestreq = name;
			}
			else if (number==bestnumber)
			{
				if (price < bestcost)
				{
					bestcost = price;
					bestnumber = number;
					namebestreq = name;
				}
			}
			for (size_t i = 0; i < number; i++)
			{
				string a;
				getline(cin, a);
			}
		}
		//output
		cout << "RFP #" << ind << endl << namebestreq << endl;
	}
}
