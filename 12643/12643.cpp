#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    while (cin >> n >> a >> b) {
        int round = 1;
        while ((a = (a + 1) / 2) != (b = (b + 1) / 2)) round++;
        cout << round << "\n";
    }
    return 0;
}
