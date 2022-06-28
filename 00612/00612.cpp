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
int mes(string a)
{
	int ret = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = i+1	; j < a.size(); j++)
		{
			if (a[j] < a[i])ret++;
		}
	}
	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int len, n;
		cin >> len >> n;
		vector<string>list(n);
		vector<pair<int, int>>refrence(n);
		for (size_t i = 0; i < n; i++)
		{
			refrence[i].second = i;
			cin >> list[i];
			refrence[i].first = mes(list[i]);
		}
		sort(refrence.begin(), refrence.end());
		for (size_t i = 0; i < n; i++)
		{
			cout << list[refrence[i].second] << endl;;
		}
		if(tc)cout << endl;
	}
}
