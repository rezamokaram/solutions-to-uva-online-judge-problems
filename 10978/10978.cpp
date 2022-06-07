# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
# include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
// 
//
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<string>list(n);
		int pos = 0;
		for (size_t i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			bool oc = 0;
			int temp = b.size();
			while (!oc)
			{
				if (temp == 1 && !list[pos].size())
				{
					oc = 1;
					list[pos] = a;
				}
				if (!list[pos].size())temp--;
				pos++;
				pos %= n;
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (i)cout << ' ';
			cout << list[i];
		}
		cout << endl;
	}
}
