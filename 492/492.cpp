#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
string sound = "AaIiOoUuEe";
bool is_letter(char a)
{
	return((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z')) ? 1 : 0;
}
//
bool is_sound(char a)
{
	return(sound.find(a) == -1) ? 0 : 1;
}
//
int main()
{
	string str;
	while (getline(cin,str))
	{
		string ans;
		string plus = "ay";
		for (size_t i = 0; i < str.length(); i++)
		{
			if ((i == 0 || !is_letter(str[i - 1])) && is_letter(str[i]))
			{
				if (is_sound(str[i]))
				{
					plus = "ay";
					ans += str[i];
				}
				else
				{
					plus = str[i];
					plus += "ay";
				}
				if ((i == str.length() - 1 || !is_letter(str[i + 1])))
				{
					ans += plus;
				}
			}
			else if (is_letter(str[i]) && (i == str.length() - 1 || !is_letter(str[i + 1])))
			{
				ans += str[i];
				ans += plus;
			}
			else
			{
				ans += str[i];
			}
		}
		cout << ans << endl;
	}
}
