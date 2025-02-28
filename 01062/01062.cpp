#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    string line;
    int tc = 0;
    while (cin >> line && line != "end") {
        vector<stack<char>> st;
        for (int i = 0; i < line.size(); ++i) {
            bool pushed = false;
            for (int j = 0; j < st.size(); ++j) {
                if (st[j].top() >= line[i]) {
                    st[j].push(line[i]);
                    pushed = true;
                    break;
                }
            }
            if (!pushed) {
                stack<char> tmp;
                tmp.push(line[i]);
                st.push_back(tmp);
            }
        }
        cout << "Case " << ++tc << ": " << st.size() << "\n";
    }
    return 0;
}
