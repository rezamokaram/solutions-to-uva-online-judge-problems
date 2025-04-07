#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char s[200][200];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    while(cin >> n){
        for(int i = 0; i < 5; i++) cin >> s[i];
        for(int i = 0; i < 4 * n; i += 4){
            if(s[0][i] == '.') cout << 1;
            else if(s[3][i] == '*') cout << 2;
            else cout << 3;
        }
        cout << "\n";
    }
    return 0;
}
