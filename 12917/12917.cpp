#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ll a,b,c;
    while (cin >> a >> b >> c) {
        cout << ((a<=c-b)?"Props win!":"Hunters win!") << "\n";
    }
    return 0;
}
