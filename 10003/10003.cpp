/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 55;
//
int arr[maxn], memo[maxn][maxn];
int len, n;
int calc(int s, int e, int mid) {
    return arr[e]-arr[s];
}
int solve(int s, int e) {
    if(memo[s][e] > -1) return memo[s][e];
    if (s+1>=e) return 0;
    if (s+2 == e) {
        return calc(s,e,s+1);
    }
    int pvot = (arr[s] + arr[e]) / 2;
    int index = lower_bound(arr+s, arr+e, pvot) - arr;
    int res = 0;
    for (int i = s+1; i < e; i++)
    {
        if (i <= s || i >= e) continue;
        int newAns = calc(s,e,i);
        int res2 = newAns + solve(s, i) + solve(i, e);
        if(!res)res=res2;
        res = min(res,res2);
    }
    memo[s][e]=res;
    return res;
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    while (cin >> len && len)
    {
        for (size_t i = 0; i < maxn; i++)
            for (size_t j = 0; j < maxn; j++)
                memo[i][j] = -1;
        
        cin >> n;
        for (size_t i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        arr[0] = 0;
        arr[n+1] = len;
        sort(arr, arr+n+2);
        int ans = solve(0, n+1);
        cout << "The minimum cutting is " << ans << ".\n";   
    }
	//
   	return 0;
}
