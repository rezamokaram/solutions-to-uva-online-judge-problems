#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<string> st;
    while (n--) {
        string cmd, name;
        cin >> cmd;
        if (cmd == "Test") {
            if (st.empty()) {
                cout << "Not in a dream\n";
            } else {
                cout << st[st.size()-1] << "\n";
            }
        } else if (cmd == "Sleep") {
            cin >> name;
            st.push_back(name);
        } else { // kick
            if(!st.empty())st.pop_back();
        }
    }
    return 0;
}
