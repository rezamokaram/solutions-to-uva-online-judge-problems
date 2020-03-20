//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
const ll MAX = 100000;
//
void input(vector<int>&a,string str)
{
	ofstream out;
	out.open("e.txt");
	out << str;
	out.close();
	ifstream in;
	in.open("e.txt");
	int d;
	while (in >> d)a.push_back(d);
	in.close();
	return;
}
int main()
{
	bool f = 0,ff=1;
	int a;
	cin >> a;
	while (1)
	{
		vector<int>tr(a);
		for (size_t i = 0; i < a; i++)
		{
			int t;
			cin >> t;
			tr[t - 1] = i;
		}
		cin.ignore();
		string str;
		vector<int>p;
		while ((getline(cin,str)))
		{
			p.clear();
			input(p, str);
			if (p.size()>1)
			{
				int ans = 0;
				
				vector<int>lis(a);
				for (size_t i = 0; i < a; i++)
				{
					lis[p[i] - 1] = i;
				}
				int arr[30][30] = { 0 };
				for (int i = a-1; i >= 0; i--)
				{
					for (int j = a-1; j >= 0; j--)
					{
						if (tr[i]==lis[j])
						{
							arr[i][j] = arr[i + 1][j + 1] + 1;
						}
						else
						{
							arr[i][j] = max(arr[i + 1][j], arr[i][j + 1]);
						}
					}
				}
				cout << arr[0][0] << endl;
			}
			else if (p.size() == 1)
			{
				a = p[0];
				break;
			}
			else
			{
				f = 1;
				break;
			}
		}
		if (f || !str.size())break;
	}
}
