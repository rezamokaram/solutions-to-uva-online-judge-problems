/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
int tc;
map<string, int> indices;
vector<string> mp[11];
vector<int> itj[201];
//
int diffStr(string a, string b) {
    if(a.size() != b.size()) return 10;
    int t=0;
    for (size_t i = 0; i < a.size(); i++)
        if(a[i] != b[i]) t++;
    
    return t;
}
//
int bfs(int s, int e) {
    vector<bool> vis(210, 0);
    vector<int> cost(210, -1);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    cost[s] = 0;
    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        for(int dest:itj[tp]) {
            if (!vis[dest]) {
                vis[dest] = 1;
                cost[dest] = cost[tp] + 1;
                q.push(dest);
            }
        }
    }
    return cost[e];
}
//
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    int finp = 0;
    cin >> tc;
    while (tc--)
    {
        if(finp){cout << "\n";}
        finp++;
        indices.clear();
        for (int i = 0; i < 11; i++)mp[i].clear();
        for (int i = 0; i < 201; i++)itj[i].clear();
        //
        int g = 0;
        string tmp;
        while (cin >> tmp && tmp != "*")
        {
            int len = tmp.size();
            int index = g;
            for(string el:mp[len]){
                if(diffStr(el, tmp) == 1) {
                    int elIndex = indices[el];
                    itj[index].push_back(elIndex);
                    itj[elIndex].push_back(index);
                }
            }
            //
            mp[len].push_back(tmp);
            indices[tmp] = index;
            g++;
        }
        getline(cin, tmp);
        while (getline(cin, tmp) && tmp != "")
        {
            string a = "", b = "";
            bool f = 0;
            for (char i:tmp)
            {
                if(i==' ')f=1;
                else if(!f) a += i;
                else b += i;
            }
            cout << a << " " << b << " " << bfs(indices[a], indices[b]) << "\n";
        }
    }
    //
    return 0;
}
