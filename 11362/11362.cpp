#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool startsWith(const std::string& a, const std::string& b) {
    int len = min(a.size(), b.size());
    for(int i = 0; i < len; i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ls[10005];
    int tc;
    cin >> tc;
    while (tc--) {
        int n, valid = 1;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> ls[i];
        sort(ls, ls + n);
        for (int i = 0; i < n - 1; ++i)
            if(startsWith(ls[i], ls[i + 1])) {valid = 0; break;}
        cout << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}
