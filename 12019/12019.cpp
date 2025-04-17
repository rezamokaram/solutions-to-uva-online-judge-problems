#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Month[13][32], i, j;
    int day = 6, Day[13] = {0, 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};
    for(i = 12; i >= 1; i--) {
        for(j = Day[i]; j >= 1; j--) {
            Month[i][j] = day;
            day--;
            if(day < 1)	day = 7;
        }
    }
    char s[8][10] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> i >> j;
        cout << s[Month[i][j]] << "\n";
    }
    return 0;
}
