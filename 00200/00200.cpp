/* wrong solution */
/* bad judge */
/* may the statement is wick */
#include <bits/stdc++.h>
using namespace std;
//
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	char mp[5000][21];
	string temp;
    int len = 0, N, J; 
	int L[26] = {0};
    while (cin >> temp && temp!="#")
    {
        for (J = 0; J < temp.size(); J++)
            mp[len][J] = temp[J];

        while (J != 21) {
            mp[len][J++] = 'a'; 
		}
		len++;
    }

    for (J = 0; J < 21; J++)
    {
        for (N = 0; N < len; N++)
       {
            if (mp[N][J] > 64 && mp[N][J] < 91)
                L [ (mp[N][J] - 65) ]++;
            if (L [ (mp[N][J] - 65) ] == 1)
                cout << mp[N][J];
        }
    }
	cout << "\n";
    return 0;
}
