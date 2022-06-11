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
bool ischar(char a)
{
	if (a >= 'a' && a <= 'z')return 1;
	if (a >= 'A' && a <= 'Z')return 1;
	return 0;
}
int main()
{
	string line;
	while (getline(cin,line))
	{
		map<char, int>ch;
		int mx = 0;
		for (size_t i = 0; i < line.size(); i++)
		{
			if(ischar(line[i]))ch[line[i]]++;
			mx = max(mx, ch[line[i]]);
		}
		string ans;
		sort(line.begin(), line.end());
		for (size_t i = 0; i < line.size(); i++)
		{
			if(!i)
			{
			if (ch[line[i]] == mx)ans += line[i];
			}
			else 
			{
				if (line[i]!=line[i-1] && ch[line[i]] == mx)ans += line[i];
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans << ' ' << mx << endl;
	}
}
