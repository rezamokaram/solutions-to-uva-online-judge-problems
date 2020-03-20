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
string mosh(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	string temp;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (binary_search(b.begin(),b.end(),a[i]))
		{
			temp += a[i];
		}
	}
	return temp;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<int>liint;
		vector<vector<int>>listt;
		listt.push_back(liint);
		listt.push_back(liint);
		listt.push_back(liint);
		vector<vector<string>>list;
		vector<string>listex;
		list.push_back(listex);
		list.push_back(listex);
		list.push_back(listex);
		int arr[12] = { 0 };
		//making input
		for (size_t i = 0; i < 3; i++)
		{
			string temp;
			cin >> temp; 
			list[i].push_back(temp);
			cin >> temp; 
			list[i].push_back(temp);
			cin >> temp;
			list[i].push_back(temp);
			for (size_t j = 0; j < 2; j++)
			{
				for (size_t z = 0; z < list[i][j].length(); z++)
				{
					if (list[i][2]=="up")
					{
						if (j==0)
						{
							arr[list[i][j][z] - 'A']++;
						}
						else
						{
							arr[list[i][j][z] - 'A']--;
						}
					}
					else if (list[i][2] == "down")
					{
						if (j == 0)
						{
							arr[list[i][j][z] - 'A']--;
						}
						else
						{
							arr[list[i][j][z] - 'A']++;
						}
					}
					else// if (list[i][0] == "d")
					{
						arr[list[i][j][z] - 'A'] += 1000;
					}
				}
			}
		}
		//
		int max = 0;
		for (size_t i = 0; i < 12; i++)
		{
			int my_max = max;
			if (my_max < 0)
			{
				my_max *= -1;
			}
			int integer = arr[i];
			if (integer > 900)
			{
				continue;
			}
			if (integer < 0)
			{
				integer *= -1;
			}
			if (my_max < integer)
			{
				max = arr[i];
			}
		}
		for (size_t i = 0; i < 12; i++)
		{
			if (arr[i] == max)
			{
				char my = 'A';
				my += i;
				if (max > 0)
				{
					cout << my << " is the counterfeit coin and it is heavy." << endl;
				}
				else
				{
					cout << my << " is the counterfeit coin and it is light." << endl;
				}
				break;
			}
		}
	}
	
}
