#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,t=0;
    cin >> tc;
    while (tc--) {
        bool p = 1;
        for (int i = 0; i < 13; ++i) {
            ll tmp; cin >> tmp;
            if (!tmp) p = 0;
        }
        cout << "Set #" << ++t << ": " << (p?"Yes":"No") << "\n";
    }
    return 0;
}
