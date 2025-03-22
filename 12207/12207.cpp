#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;
    int p, c;
    while (cin >> p >> c && p && c) {
        cout << "Case " << ++tc << ":\n";
        list<int>q;
        for (int i = 0; i < min(p, c); ++i) {
            q.push_back(i+1);
        }
        map<int,int>cnt;
        while (c--) {
            char cmd;
            cin >> cmd;
            if (cmd == 'E') {
                int member;
                cin >> member;
                q.remove(member);
                q.push_front(member);
            } else {
                int fr = q.front();
                cout << fr << "\n";
                q.push_back(fr);
                q.pop_front();
            }
        }
    }
    return 0;
}
