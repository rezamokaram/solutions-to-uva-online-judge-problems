/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
typedef pair<int,int> pii;
map<char, pair<int,int>>mv;
//
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	mv['N'] = pii(-1,0);
	mv['S'] = pii(1,0);
	mv['E'] = pii(0,1);
	mv['W'] = pii(0,-1);
	//
	int n,m,st;
	while (cin >> n >> m >> st && n && m && st)
	{
		int g=0, lp=0;
		vector<vector<int>> v(n, vector<int>(m, 0));
		vector<vector<char>> c(n, vector<char>(m));
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				cin >> c[i][j];
		
		pii pos(0, st-1);
		v[pos.first][pos.second] = ++g;
		pii next = pii(pos.first + mv[c[pos.first][pos.second]].first,pos.second + mv[c[pos.first][pos.second]].second);
		while (1)
		{
			if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) break;
			if(v[next.first][next.second] > 0) {
				lp = v[next.first][next.second];
				break;
			}
			pos = next;
			v[pos.first][pos.second] = ++g;
			next = pii(pos.first + mv[c[pos.first][pos.second]].first,pos.second + mv[c[pos.first][pos.second]].second);
		}
		if (lp) {
			cout << g-(g-lp+1) << " step(s) before a loop of " << g-lp+1 << " step(s)\n";
		} else {
			cout << g << " step(s) to exit\n";
		}
	}
	//
   	return 0;
}
