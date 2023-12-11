/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 1e4 + 20;
int n, m, l, ans=0;
vector<int> adj[maxn];
bool v[maxn];
void dfs(int x) {
    if(v[x])return;
    v[x]=1;
    for (int dest : adj[x])
    {
        if(!v[dest]) {
            dfs(dest);
        }
    }
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> l;
        for (size_t i = 0; i < n+2; i++)
        {
            adj[i].clear();
            v[i]=0;
        }
        ans=0;

        for (size_t i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for (size_t i = 0; i < l; i++)
        {
            int t;
            cin >> t;
            dfs(t);
        }

        for (int i = 1; i <= n; i++)
            if(v[i])ans++;
            
        cout << ans << endl;
    }   
    //
    return 0;
}
