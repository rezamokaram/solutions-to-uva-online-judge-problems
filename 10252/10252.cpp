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
//string al = "abcdefghijklmnopqrstuvwxyz";
//

int main()
{
	string a, b;
	while (getline(cin,a))
	{
		getline(cin, b);
		//int ela[28] = { 0 };
		//int elb[28] = { 0 };
		char ans[1000];
		int index = 0;
		for (size_t i = 0; i < a.length(); i++)
		{
			for (size_t j = 0; j < b.length(); j++)
			{
				if (a[i] == b[j])
				{
					b[j] = 'A';
					ans[index] = a[i];
					index++;
					break;
				}
			}
		}
		ans[index] = '\0';
		sort(ans, ans + index);
		cout << ans << endl;
	}
}
