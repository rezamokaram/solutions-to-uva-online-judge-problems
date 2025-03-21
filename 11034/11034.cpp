#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        queue<long double> right, left;
        long double ferry;
        long long int cars;
        cin >> ferry >> cars;
        ferry *= 100;
        for (int i = 0; i < cars; ++i) {
            long double len;
            string side;
            cin >> len >> side;
            if (side == "left") left.push(len);
            else right.push(len);
        }

        bool curSide = true;
        int times = 0;
        while (!right.empty() || !left.empty()) {
            if (curSide) { // left
                long double cargo = 0;
                while (!left.empty() && cargo + left.front() <= ferry) {
                    cargo += left.front();
                    left.pop();
                }
            } else { // right
                long double cargo = 0;
                while (!right.empty() && cargo + right.front() <= ferry) {
                    cargo += right.front();
                    right.pop();
                }
            };
            //
            times++;
            curSide = !curSide;
        }
        cout << times << "\n";
    }
    return 0;
}
