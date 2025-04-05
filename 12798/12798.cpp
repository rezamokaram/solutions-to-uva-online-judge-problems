#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin >> n >> m) {
        int pr = 0;
        for (int i = 0; i < n; ++i) {
            int c = 1;
            for (int j = 0; j < m; ++j) {
                int tmp;
                cin >> tmp;
                if (!tmp) c = 0;
            }
            pr += c;
        }
        cout << pr << "\n";
    }
    return 0;
}
