/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
int n;
string mp[100];
//
void dfs(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= n) return;
    if(mp[i][j] == '.') return;
    mp[i][j] = '.';
    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i+1, j);
    dfs(i-1, j);
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    int tc, ct = 0;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            cin >> mp[i];
        }
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if(mp[i][j] == 'x') {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout << "Case " << ++ct << ": " << ans << "\n";
    }
    //
    return 0;
}
