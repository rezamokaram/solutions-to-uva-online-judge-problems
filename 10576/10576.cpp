/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 5e5 + 20;
//

int calc(int s, int d)
{
    int mx = 5;
    while (mx > 0 && s * mx  - d * (5 - mx) >= 0)
    {
        --mx;
    }
    
    int mn = 5 - mx;
    // Can't have any positive in string of 5 months make deficit
    if (mx == 0)
        return -1;
    
    int sum = 0;
    int pos = 0;
    
    while (pos < 12)
    {
        int num = min(12 - pos, mx);
        sum += num * s;
        
        pos += num;
        int neg = min(12 - pos, mn);
        sum -= neg * d;
        pos += neg;
    }
    
    return sum;
}

int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	int s, d;
    while (cin >> s >> d)
    {
        int surplus = calc(s, d);
        if (surplus < 0)
            cout << "Deficit\n";
        else
            cout << surplus << '\n';
    }
	//
   	return 0;
}
