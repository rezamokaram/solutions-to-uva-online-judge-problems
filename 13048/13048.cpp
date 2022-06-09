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

int main()
{
	int tc,cs=1;
	cin >> tc;
	while (tc--)
	{
		string line;
		cin >> line;
		int ans = 0;
		for (size_t i = 0; i < line.size(); i++)
		{
			bool f = 1;
			if (line[i] != '-')f = 0;
			if (i < line.size() - 2)
			{
				if (line[i + 2] == 'B')f = 0;
			}
			if (i < line.size() - 1)
			{
				if (line[i + 1] == 'B' || line[i + 1] == 'S')f = 0;
			}
			if (i)
			{
				if (line[i - 1] == 'S')f = 0;
			}
			if (f)ans++;
		}
		cout << "Case " << cs++ << ": " << ans << endl;
	}
}
