# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
# include <iomanip>
# include <algorithm>
# include <queue>
# include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
//
int main()
{
	llu a, b,cs=0;
	while (cin>>a>>b)
	{
		if (!a && !b)break;
		llu t = a / b;
		if (a%b==0)t--;
		cout << "Case " << ++cs << ": ";
		if (t > 26) cout << "impossible";
		else cout << t;
		cout << endl;
	}
}
