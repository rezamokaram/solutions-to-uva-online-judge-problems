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
       string a, b;
       cin >> a >> b;
       int res = 0, aOnes = 0, bOnes = 0, aOneDiff = 0, aZeroDiff = 0, aQs = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '1') aOnes++;
            if (b[i] == '1') bOnes++;
            if (a[i] == '?') aQs++;
            if (a[i] == '0' && a[i]!=b[i]) aZeroDiff++;
            if (a[i] == '1' && a[i]!=b[i]) aOneDiff++;
        }
        if (aOnes > bOnes) res = -1;
        else res = aQs + max(aZeroDiff, aOneDiff);
       cout  << "Case " << ++c << ": " << res << "\n";
    }
    return 0;
}
