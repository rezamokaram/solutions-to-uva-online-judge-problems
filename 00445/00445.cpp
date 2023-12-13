/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
	string line;
	while (getline(cin, line))
	{
		// cout << "==> " << line << "\n";
		int num = 0;
		for (char c : line)
		{
			if(c >= '0' && c <= '9') {
				num += c - '0';
			} else if(c == '!') {
				num = 0;
				cout << "\n";
			}else if(c == 'b') {
				for (size_t i = 0; i < num; i++)
				{
					cout << " ";
				}
				num=0;
			} else {
				for (size_t i = 0; i < num; i++)
				{
					cout << c;
				}
				num=0;
			}
		}
		
		cout << "\n";
	}
	
    //
    return 0;
}
