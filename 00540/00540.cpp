#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;
    int n;
    while (cin >> n && n) {
        cout << "Scenario #" << ++tc << "\n";
        //
        map<int,int> tmNumber;
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int member;
                cin >> member;
                tmNumber[member] = i;
            }
        }
        //
        string cmd;
        vector<queue<int>> allQs(n);
        vector<bool> isInQ(n, false);
        queue<int> referer;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                int member;
                cin >> member;
                int team = tmNumber[member];
                allQs[team].push(member);
                if (!isInQ[team]) {
                    referer.push(team);
                    isInQ[team] = true;
                }
            } else {
                int team = referer.front();
                int member = allQs[team].front();
                allQs[team].pop();
                if (allQs[team].empty()) {
                    referer.pop();
                    isInQ[team]= false;
                }
                cout << member << "\n";
            }
        }
        //
        cout << "\n";
    }
    return 0;
}
