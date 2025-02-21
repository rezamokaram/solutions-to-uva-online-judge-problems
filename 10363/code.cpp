#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int tc, ntc = 0;
    cin >> tc;
    while (tc--) {

        vector<string> lines(3);
        cin >> lines[0] >> lines[1] >> lines[2];

        // test
        ntc++;
        if (ntc == 10850) {
//            cerr << lines[0] << endl << lines[1] << endl << lines[2];
        }
        // end test

        int xno = 0, ono = 0;
        bool allCharOK = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (lines[i][j] == 'X') {
                    xno++;
                } else if (lines[i][j] == 'O') {
                    ono++;
                } else if (lines[i][j] != '.') {
                    allCharOK = false;
                }
            }
        }
        if (!allCharOK || !(ono == xno || ono + 1 == xno)) {
            cout << "no\n";
            continue;
        }
        vector<string> answers;
        for (int i = 0; i < 3; ++i) {
            answers.push_back(lines[i]);

            string tmp = "";
            tmp += lines[0][i];
            tmp += lines[1][i];
            tmp += lines[2][i];
            answers.push_back(tmp);
        }

        string tmp = "";
        tmp += lines[0][0];
        tmp += lines[1][1];
        tmp += lines[2][2];
        answers.push_back(tmp);

        tmp = "";
        tmp += lines[0][2];
        tmp += lines[1][1];
        tmp += lines[2][0];
        answers.push_back(tmp);

        int xwinno = 0, owinno = 0;
        for (int i = 0; i < answers.size(); ++i) {
            if (answers[i] == "XXX") {
                xwinno++;
            } else if (answers[i] == "OOO") {
                owinno++;
            }
        }
        if (xwinno > 2 || owinno >= 2 || (owinno == 1 && xwinno == 1) || (owinno == 1 && xno != ono) ||
            (xwinno == 1 && xno != ono + 1)) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }
    }
    return 0;
}
