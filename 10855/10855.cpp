#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
void rotate(vector<string>&list)
{
	int len = list.size();
	vector<string>nv;
	string ex;
	for (size_t i = 0; i < len; i++)
	{
		ex += ' ';
	}
	for (size_t i = 0; i < len; i++)
	{
		nv.push_back(ex);
		for (size_t j = 0; j < len; j++)
		{
			nv[i][j] = list[len - 1 - j][i];
		}
	}
	list.clear();
	for (size_t i = 0; i < len; i++)
	{
		list.push_back(nv[i]);
	}
	nv.clear();
	//end
	return;
}
//
int main()
{
	int b, s;
	while (cin >> b >> s && b && s)
	{
		vector<string>big;
		for (size_t i = 0; i < b; i++)
		{
			string temp;
			cin >> temp;
			big.push_back(temp);
		}
		int number[4] = { 0 };
		vector<vector<string>> smals (4);
		for (size_t i = 0; i < s; i++)
		{
			string temp;
			cin >> temp;
			smals[0].push_back(temp);
		}
		//making smals
		for (size_t j = 1; j < 4; j++)
		{
			for (size_t i = 0; i < s; i++)
			{
				string temp;
				temp = smals[j-1][i];
				smals[j].push_back(temp);
			}
			rotate(smals[j]);
		}
		//end of making
		/*for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < s; j++)
			{
				cout << smals[i][j] << endl;
			}
			cout << endl;
		}
		cout << endl << "ans:" << endl;*/
		//checking
		for (size_t i = 0; i < b - (s - 1); i++)
		{
			for (size_t j = 0; j < b-(s-1); j++)
			{
				for (size_t q = 0; q < 4; q++)
				{
					bool f = true;
					for (size_t x = 0; x < s; x++)
					{
						for (size_t y = 0; y < s; y++)
						{
							if (big[i+x][j+y]!=smals[q][x][y])
							{
								f = false;
								break;
							}
						}
						if (!f)
						{
							break;
						}
					}
					if (f)
					{
						number[q]++;
					}
				}
			}
		}
		cout << number[0] << " " << number[1] << " " << number[2] << " " << number[3] << endl;
	}
}
