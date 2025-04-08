#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, c = 0;
    cin >> tc;
    while(tc--){
        int n, cnt = 0, ans = -1;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            char d;
            cin >> d;
            if (d == 'W') cnt = 0;
            else cnt++;
            if (cnt == 3 && ans == -1) ans = i + 1;
        }
        cout << "Case " << ++c << ": " << (ans == -1? "Yay! Mighty Rafa persists!" : to_string(ans)) << "\n";
    }
    return 0;
}
