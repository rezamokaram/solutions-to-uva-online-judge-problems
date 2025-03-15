#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string a = "";
        for (int i = 0; i < 5; ++i) {
            string b;
            cin >> b;
            a += b;
        }
        cout << ((a == "12345" || a == "23456")?"Y\n":"N\n");
    }
    return 0;
}
