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
       string str;
       cin >> str;
       int res = 0;
       stack<int>st;
        for (int i = 0; i < str.length(); ++i) {
            if(str[i] == '\\') {
                st.push(i);
            } else if(str[i] == '/' && !st.empty()) {
                res += i - st.top();
                st.pop();
            }
        }
       cout << res << "\n";
    }
    return 0;
}
