/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//
const ll maxn = 5e5 + 20;
set<ll>nodes;
map<ll , ll> par;
ll n = 0, e = 0, v, u, cases = 0, flag = 1;

ll findp(ll x) {
	return (par[x] == 0 ? x : par[x] = findp(par[x]));
}
bool check() {
	// if(e != ll(nodes.size()) - 1)return 0;
	if(!flag) {
		flag = 1;
		return 0;
	}
	ll fp = findp( *nodes.begin() );
	for (ll i : nodes)
	{
		if(findp(i) != fp) return 0;
	}
	return 1;
}

int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	
	while (cin >> v >> u && v >= 0 && u >= 0)
	{
		if(v==0 && u == 0) {
		
			// cerr << v << " ** " << u <<" // " << cases + 1 << "  -inp\n";
			if(!check()) cout << "Case " << ++cases << " is not a tree.\n";
			else cout << "Case " << ++cases << " is a tree.\n";

			// for (ll i : nodes)
			// 	par[i] = 0;
			par.clear();
			n = 0;
			e = 0;
			flag = 1;
			nodes.clear();
			continue;
		}
		if(nodes.find(v) == nodes.end()) par[v] = 0;
		if(nodes.find(u) == nodes.end()) par[u] = 0;

		n = max(n, max(v, u));
		nodes.insert(u);
		nodes.insert(v);
		e++;
		if(findp(u) == findp(v)){flag=0;continue;}
		if(findp(u) != u){flag=0;continue;}
		par[u] = findp(v);
		findp(v);
		findp(u);
	}
    //
    return 0;
}
