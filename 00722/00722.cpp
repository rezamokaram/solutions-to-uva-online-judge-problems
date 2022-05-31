# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
int main()
{
	int tc;
	cin >> tc;
	bool kk = 0;
	while (tc--)
	{
		int r, c;
		cin >> r >> c;
		vector<string>m;
		vector<vector<bool>>v;
		string line;
		getline(cin, line);
		//if(kk)getline(cin, line);
		while (getline(cin,line) && line.size())
		{
			m.push_back(line);
			vector<bool>temp(line.size(), 0);
			v.push_back(temp);
		}
		queue < pair<int, int>> sf;
		sf.push(pair<int, int>(r-1, c-1));
		int lake = 0;
		while (sf.size())
		{
			pair<int, int>temp = sf.front();
			int row = temp.first, col = temp.second;
			sf.pop();
			lake++;
			v[row][col] = 1;
			//neighbors
			if (row > 0)
			{
				if (m[row - 1][col] == '0' && !v[row - 1][col])
					sf.push(pair<int, int>(row - 1, col)),v[row-1][col] = 1;
			}
			if (row < m.size()-1)
			{
				if (m[row + 1][col] == '0' && !v[row + 1][col])
					sf.push(pair<int, int>(row + 1, col)),v[row+1][col]=1;
			}
			if (col > 0)
			{
				if (m[row][col-1] == '0' && !v[row][col-1])
					sf.push(pair<int, int>(row, col-1)),v[row][col-1] = 1;
			}
			if (col < m[0].size() - 1)
			{
				if (m[row][col+1] == '0' && !v[row][col+1])
					sf.push(pair<int, int>(row, col+1)), v[row][col+1] = 1;
			}
		}
		if (kk)cout << endl;
		cout << lake << endl;
		kk = 1;
	}
}
