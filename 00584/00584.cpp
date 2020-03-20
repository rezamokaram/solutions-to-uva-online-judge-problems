#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
int main()
{
	string temp;
	while (getline(cin,temp))
	{
		if (temp[0]=='G')
		{
			break;
		}
		string ch;
		for (size_t i = 0; i < temp.length(); i++)
		{
			if (temp[i]!=' ')
			{
				ch += temp[i];
			}
		}
		vector<int>marks;
		for (size_t i = 0; i < ch.length(); i++)
		{
			if (ch[i]>='0' && ch[i]<='9')
			{
				marks.push_back(ch[i] - '0');
			}
			else if (ch[i]=='X')
			{
				marks.push_back(10);
			}
			else
			{
				marks.push_back(10 - marks[i - 1]);
			}
		}
		int sum = 0;
		int frms = 0;
		for (size_t i = 0; i < marks.size(); i++)
		{
			if (frms==10)
			{
				break;
			}
			if (marks[i]==10)
			{
				frms++;
				sum += marks[i] + marks[i + 1] + marks[i + 2];
			}
			else if (marks[i]+marks[i+1]==10)
			{
				sum += marks[i] + marks[i + 1] + marks[i + 2];
				i++;
				frms++;
			}
			else
			{
				sum += marks[i] + marks[i + 1];
				i++;
				frms++;
			}
		}
		if (sum>300)
		{
			sum = 300;
		}
		cout << sum << endl;
	}
}
