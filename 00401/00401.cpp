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
string pable = "AEHIJLMOSTUVWXYZ12358";
string plins = "A3HILJMO2TUVWXY51SEZ8";
//
bool search(string str, char ch)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i]==ch)
		{
			return true;
		}
	}
	return false;
}
//
bool miror(string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		char a = str[i];
		if (!search(pable,a))
		{
			return false;
		}
	}
	return true;
}
//
bool pali(string str)
{
	for (size_t i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}
//
int isearch(string str, char ch)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}
	return -1;
}
//
bool mirorpali(string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		char a = str[i];
		int index = isearch(pable,a);
		if (index>=0)
		{
			if (str[str.length()-i-1] != plins[index])
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
//
int main()
{
	string str;
	bool start = false;
	while (cin >> str)
	{
		/*if (start)
		{
			cout << endl << endl;
		}*/
		start = true;
		bool f = miror(str);
		bool ff = pali(str);
		bool fff = mirorpali(str);
		if (fff && ff)
		{
			cout << str << " -- is a mirrored palindrome.";
		}
		else if (fff)
		{
			cout << str << " -- is a mirrored string.";
		}
		else if (ff)
		{
			cout << str << " -- is a regular palindrome.";
		}
		else //if (!f && !ff)
		{
			cout << str << " -- is not a palindrome.";
		}
		cout << endl << endl;
	}
}
