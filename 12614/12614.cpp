#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, n, ic = 0, max = -1, num = 0;
    cin >> tc;
    while(tc--){
        cin >> n;
        while(n--){
            cin >> num;
            if(max < num) max = num;
        }
        cout << "Case " << ++ic << ": " << max << "\n";
        max=-1;
    }
    return 0;
}
