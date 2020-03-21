#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int nch;
		cin >> nch;
		string str;
		str += ' ';
		vector<int>pay;
		pay.push_back(0);
		while (nch--)
		{
			char aa;
			int pp;
			cin >> aa >> pp;
			str += aa;
			pay.push_back(pp);
		}
		int ns;
		int sum = 0;
		cin >> ns;
		cin.ignore();
		while (ns--)
		{
			string temp;
			getline(cin, temp);
			for (size_t i = 0; i < temp.length(); i++)
			{
				int index = str.find(temp[i]);
				if (index)
				{
					sum += pay[index];
				}
				/*for (size_t j = 0; j < str.length(); j++)
				{
					if (temp[i]==str[j])
					{
						sum += pay[j];
						break;
					}
				}*/
			}
		}
		//output
		int sent = sum % 100;
		cout << sum / 100 << ".";
		if (sent<10)
		{
			cout << 0;
		}
		cout << sent << "$" << endl;
	}
}
