/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 5e5 + 20;
//
string ops="-+*";
vector<string> subs;
vector<int> fv(5);
void bt(string sb) {
	if (sb.size() == 4) {
		subs.push_back(sb);
		return;
	}
	for (size_t i = 0; i < 3; i++)
	{
		bt(sb + ops[i]);
	}
}
bool calc(int el, vector<int> fiv) {
	int ans = fiv[0];
	for (size_t i = 1; i < 5; i++)
	{
		if (subs[el][i-1] == '-') ans -= fiv[i];
		else if (subs[el][i-1] == '+') ans += fiv[i];
		else if (subs[el][i-1] == '*') ans *= fiv[i];
	}
	// cout << ans << endl;
	return ans == 23;
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	bt("");
	while (cin >> fv[0]>> fv[1]>> fv[2]>> fv[3] >> fv[4] && fv[0] && fv[1] && fv[2] && fv[3] && fv[4])
	{
		bool f = 0;
		sort(fv.begin(), fv.end());
		do
		{
			for (size_t i = 0; i < subs.size(); i++)
			{
				// cout << subs[i] << endl;
				f = calc(i, fv);
				if (f) break;
			}
			if (f) break;
		} while (next_permutation(fv.begin(), fv.end()));
		cout << (f?"Possible":"Impossible") << "\n";
	}
	//
   	return 0;
}
