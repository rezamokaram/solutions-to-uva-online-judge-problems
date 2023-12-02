/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 5e5 + 20;
//
set<int>prime;
int arr[20], n;
bool v[20];
int sub[20];
//
void bt(int len){
	if(len == n) {
		for (int i = 0; i < n; i++)
		{
			cout << sub[i] << " \n"[i==n-1];
		}
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if(v[i])continue;
		if(prime.find(sub[len-1] + i) != prime.end()) {
			if (len==n-1 && prime.find(1 + i) == prime.end())continue;
			v[i] = 1;
			sub[len] = i;
			bt(len + 1);
			v[i] = 0;
		}
	}
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	v[1] = 0;
	prime.insert(2);
	prime.insert(3);
	prime.insert(5);
	prime.insert(7);
	prime.insert(11);
	prime.insert(13);
	prime.insert(17);
	prime.insert(19);
	prime.insert(23);
	prime.insert(29);
	prime.insert(31);
	//
	for (size_t i = 1; i < 19; i++)
	{
		arr[i] = i;
	}
	int tc = 1;
	sub[0]=1;
	while (cin >> n)
	{
		for (int i = 2; i < 20; i++)
			v[i] = 0;

		if(tc>=2)cout << "\n";
		cout << "Case " << tc++ << ":\n";
		bt(1);
	}
   	return 0;
}
