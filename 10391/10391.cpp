#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ls;
    map<string, bool>mp;
    string s, fs, ss;
    while (cin >> s) {
        ls.push_back(s);
    }
    sort(ls.begin(),ls.end());
    for(int i=0; i<ls.size(); i++)
    {
        if(ls[i].size()==1) continue;
        for(int j=1; j<ls[i].size(); j++)
        {
            fs = ls[i].substr(0,j);
            ss = ls[i].substr(j,ls[i].size()-1);
            if((binary_search(ls.begin(),ls.end(), fs)) && (binary_search(ls.begin(),ls.end(), ss)))
            {
                cout << ls[i] << endl;
                break;
            }
        }
    }
    return 0;
}
