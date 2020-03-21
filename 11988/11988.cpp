#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int llu;
typedef long long int ll;
//
int main()
{
    //cout << 1 << endl;
    string a;
    while (getline(cin, a))
    {
        //cout << 3 << endl;
        string end, mid;
        for (size_t i = 0; i < a.size() && a[i] != '[' && a[i] != ']'; i++)
        {
            mid += a[i];
        }
        //cout << 4 << endl;
        bool ok = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] == ']')
            {
                ok = 1;
                continue;
            }
            else if (a[i] == '[')
            {
                ok = 0;
                continue;
            }
            if (ok == 1)
            {
                end.push_back(a[i]);
            }
        }

        //cout << 5 << endl;
        ok = 0;
        vector<string> first;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] == '[')
            {
                first.push_back("");
                ok = 1;
                continue;
            }
            else if (a[i] == ']')
            {
                ok = 0;
                continue;
            }
            if (ok)
            {
                first[first.size() - 1] += a[i];
            }
        }
        //cout << 88 << endl;
        for (int i = first.size() - 1; i >= 0; i--)
        {
            cout << first[i];
        }
        cout << mid << end << endl;
    }
    //cout << 2 << endl;
}
