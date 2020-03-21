#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
string sent(string str)
{
	char nstr[10000];
	int index = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i]>='a' && str[i]<='z')
		{
			nstr[index] = str[i];
			index++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			nstr[index] = str[i] + 32;
			index++;
		}
	}
	nstr[index] = '\0';
	string nnstr = nstr;
	return nnstr;
}
//
string rev(string str)
{
	char nstr[10000];
	int index = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		nstr[index] = str[i];
		index++;
	}
	nstr[index] = '\0';
	string nnstr = nstr;
	return nnstr;
}
//
int main()
{
	string a;
	while (getline(cin,a))
	{
		if (a=="DONE")
		{
			break;
		}
		string na = sent(a);
		string nna = rev(na);
		char nnn[10000];
		for (size_t i = 0; i < nna.length(); i++)
		{
			nnn[i] = nna[i];
		}
		if (na==nna)
		{
			cout << "You won't be eaten!" << endl;
		}
		else
		{
			cout << "Uh oh.." << endl;
		}
	}
}
