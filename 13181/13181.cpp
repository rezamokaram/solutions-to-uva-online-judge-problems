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
	string line;
	while (cin>>line)
	{
		vector<int>arr(line.size(), -1);
		int perv = -1;
		for (size_t i = 0; i < line.size(); i++)
		{
			if (perv != -1)
			{
				if (line[i] == 'X')perv = i, arr[i] = -1;
				else
				{
					arr[i] = i - perv - 1;
				}
			}
			if (line[i] == 'X')perv = i,arr[i]=-1;
		}
		int ans = -1;
		perv = -1;
		for (int i = line.size()-1; i >= 0; i--)
		{
			if (perv != -1)
			{
				if (line[i] == 'X')perv = i, arr[i] = -1;
				else
				{
					if (arr[i] != -1) arr[i] = min(arr[i], perv - i - 1);
					else arr[i] = perv - i - 1;
				}
			}
			if (line[i] == 'X')perv = i,arr[i]=-1;
			ans = max(ans, arr[i]);
		}
		cout << ans << endl;
	}
}
