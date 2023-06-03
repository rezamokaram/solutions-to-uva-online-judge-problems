#include <bits/stdc++.h>
using namespace std;
//
#define all(X) X.begin(), X.end()
//
typedef long long int ll;
typedef long long unsigned int llu;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//
//
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //
  int tc;
  cin >> tc;
  while(tc--)
  {
   int n;
   cin>>n;
   vector<set<int>>adj(n+4);
   for (int i = 0; i < n; ++i)
   {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j)
      {
         int d;
         cin >> d;
         if(d>n || d<0)continue;
         adj[i+1].insert(d);
         adj[d].insert(i+1);
      }
   }
   ll ans=0;
   vector<int>color(n+4,-1);
   for (int i = 1; i <= n; ++i)
   {
      if(color[i]!=-1)continue;
      bool isBipartite = 1;
      int red = 0, black = 0;
      queue<int>q;
      color[i] = 0;
      vector<int>cnt(2,0);
      cnt[0]++;
      q.push(i);
      while(!q.empty())
      {
         int tp = q.front();
         q.pop();
         for (int it:adj[tp])
         {
            if(color[it]==-1)
            {
               color[it] = 1 - color[tp];
               cnt[color[it]]++;
               q.push(it);
            }
            else if(color[tp] == color[it])
            {
               isBipartite=0;
            }
         }
      }
      if(isBipartite)ans += max(cnt[0],cnt[1]);
   }

   cout<<ans<<endl;
  }
  return 0;
}
