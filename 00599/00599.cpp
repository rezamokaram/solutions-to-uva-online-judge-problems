#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int findp(vector<int>& par, int node) {
    if (par[node] == 0 || par[node] == node) return node;
    par[node] = findp(par, par[node]);
    return par[node];
}

int main()
{
    int tc = 0;
    cin >> tc;
    while (tc--) {
        map<int, int> mp;
        vector<int> par(40, 0);
        string line;
        while (cin >> line && line[0] != '*') {
            int start = line[1] - 'A' + 1;
            int end = line[3] - 'A' + 1;
            int ps = findp(par, start);
            int pe = findp(par, end);
            if (ps != pe) {
                par[pe] = ps;
            }
        }
        cin >> line;
        for (int i = 0; i <line.size(); ++i) {
            if (line[i] >= 'A' && line[i]<='Z') {
                int node = line[i] - 'A' + 1;
                int p = findp(par, node);
                mp[p]++;
            }
        }
        int trees = 0, acrons = 0;
        for(pii i:mp) {
            if (i.second > 1) {
                trees++;
            } else {
                acrons++;
            }
        }
        cout << "There are " << trees << " tree(s) and " << acrons << " acorn(s).\n";
    }
    return 0;
}
