#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n, m, rn = 0;
    string tmp;
    while (cin >> n && n)
    {
        getline(cin,tmp);
        cout << "Run #" << ++rn << ": ";
        vector<string> answers(n);
        for (int i = 0; i < n; ++i) {
            getline(cin,answers[i]);
        }
        cin >> m;
        getline(cin,tmp);
        vector<string> outputs(m);
        for (int i = 0; i < m; ++i) {
            getline(cin,outputs[i]);
        }
        if (n == m) {
            bool allSame = true;
            for (int i = 0; i < n; ++i) {
                if (outputs[i] != answers[i]) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                cout << "Accepted\n";
                continue;
            }
        }
        // check pr Err
        string ans = "", out = "";
        for (int i = 0; i < n; ++i) {
            for (char j: answers[i]) {
                if (j >= '0' && j <= '9') {
                    ans += j;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (char j: outputs[i]) {
                if (j >= '0' && j <= '9') {
                    out += j;
                }
            }
        }
        if (out == ans) {
            cout << "Presentation Error\n";
            continue;
        }
        // wr Err
        cout << "Wrong Answer\n";
    }
    
    return 0;
}
