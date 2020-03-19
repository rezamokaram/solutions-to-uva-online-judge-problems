#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int tc, arr[1000];
	string strint;
	cin >> tc;
	
	for (size_t z = 0; z < tc; z++)
	{
		cin.ignore();
		cin.ignore();
		getline(cin, strint);
		int len = strint.length();
		int numint = 0;
		for (size_t j = 0; j < len; j++)
		{
			int counter = 0;
			while (strint[j + counter] != ' '  && counter + j < len)
			{
				counter++;
			}
			if (counter != 0)
			{
				int temp = counter, sum = 0;
				counter--;
				for (size_t i = 0; i < temp; i++)
				{
					sum += (strint[i + j] - 48)*pow(10, counter);
					counter--;
				}
				arr[numint] = sum;
				j += temp;
				numint++;
			}
		}


		vector<string> list;
		int arr2[1000];
		for (size_t i = 0; i < numint; i++)
		{
			string a;
			cin >> a;
			list.push_back(a);
			arr2[arr[i] - 1] = i;
		}
		for (size_t i = 0; i < numint; i++)
		{
			cout << list[arr2[i]] << endl;
		}
		if (z != tc - 1)
		{
			cout << endl;
		}
	}
}
