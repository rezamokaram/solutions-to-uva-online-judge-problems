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
	int n;
	while (cin >> n)
	{
		vector<llu>ans(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> ans[i];
		}
		sort(ans.begin(), ans.end());
		for (size_t k = 1; k < n; k++)
		{
			vector<llu>number(n);
			for (size_t i = 0; i < n; i++)
			{
				cin >> number[i];
			}
			sort(number.begin(), number.end());
			priority_queue<pair<llu, llu>, vector<pair<llu, llu>>, greater<pair<llu, llu>>>pq;
			for (size_t i = 0; i < n; i++)
			{
				pq.push(pair<llu, llu>(ans[i] + number[0], 0));
			}
			for (size_t i = 0; i < n; i++)
			{
				pair<llu, llu> temp = pq.top();
				pq.pop();
				ans[i] = temp.first;
				if (temp.second + 1 < n)
					pq.push(pair<llu, llu>(temp.first - number[temp.second] + number[temp.second + 1], temp.second + 1));
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			if (i)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}
