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
int ptime[3003] = { 0 };
int main()
{
	string r;
	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;
	int ptime[3003] = { 0 };
	while (cin>>r && r!="#")
	{
		pair<int, int> temp;
		int qnum, ttime;
		cin >> qnum >> ttime;
		ptime[qnum]=ttime;
		temp.first = ttime;
		temp.second = qnum;
		pq.push(temp);
	}
	int k;
	cin >> k;
	while (k--)
	{
		pair<int, int> temp = pq.top();
		pq.pop();
		cout << temp.second << endl;
		temp.first += ptime[temp.second];
		pq.push(temp);
	}
}
