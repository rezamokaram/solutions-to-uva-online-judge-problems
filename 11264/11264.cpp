/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
//
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n, ans = 0, sum=1;
        cin >> n;
        vector<long long> arr(n);
        ans = (n>1?2:1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (size_t i = 1; i < n-1; i++)
        {
            if(sum + arr[i] < arr[i+1]) {
                sum+=arr[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
    //
    return 0;
}
