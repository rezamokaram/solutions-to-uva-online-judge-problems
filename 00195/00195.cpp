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
string al = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
int find_index(char str)
{
	for (size_t i = 0; i < al.length(); i++)
	{
		if (al[i]==str)
		{
			return i;
		}
	}
	return -1;
}
bool ssort(string a1, string a2)
{
	for (size_t i = 0; i < a1.length(); i++)
	{
		int aa1 = find_index(a1[i]);
		int aa2 = find_index(a2[i]);
		if (aa1 == aa2)
		{
			continue;
		}
		else if (aa1>=0 && aa2>=0)
		{
			return (aa1 > aa2);
		}
		else
		{
			return (a1[i] > a2[i]);
		}
	}
	return true;
}
//
int main()
{
	
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		vector<string>list;
		do
		{
			list.push_back(str);
		} while (next_permutation(str.begin(), str.end()));
		sort(list.begin(), list.end(),ssort);
		for (int i = list.size() - 1; i >=0 ; i--)
		{
			cout << list[i] << endl;
		}
	}
}
