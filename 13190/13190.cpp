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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		int mtime[10001];
		priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int,string>>>, greater<pair<int, pair<int, string>>>> pq;
		for (size_t i = 0; i < n; i++)
		{
			string name;
			int period;
			cin >> name >> period;
			mtime[i] = period;
			pair<int, pair<int, string>> temp;
			temp.first = period;
			temp.second.first = i;
			temp.second.second = name;
			pq.push(temp);
		}
		for (size_t i = 0; i < k; i++)
		{
			pair<int, pair<int, string>> temp;
			temp = pq.top();
			pq.pop();
			cout << temp.first << ' ' << temp.second.second << endl;
			temp.first += mtime[temp.second.first];
			pq.push(temp);
		}
	}
}
