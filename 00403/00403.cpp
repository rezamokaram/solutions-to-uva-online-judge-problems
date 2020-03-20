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
string strsaz(string str)
{
	string temp;
	for (size_t i = 1; i < str.length()-1; i++)
	{
		/*if (str[i]==' ')
		{
			temp += '.';
			continue;
		}*/
		temp += str[i];
	}
	return temp;
}
vector<string>alph;
void f()
{
	alph.push_back(".***..*...*.*****.*...*.*...*.");//A
	alph.push_back("****..*...*.****..*...*.****..");//B
	alph.push_back(".****.*...*.*.....*......****.");//C
	alph.push_back("****..*...*.*...*.*...*.****..");//D//?
	alph.push_back("*****.*.....***...*.....*****.");//E
	alph.push_back("*****.*.....***...*.....*.....");//F
	alph.push_back(".****.*.....*..**.*...*..***..");//G
	alph.push_back("*...*.*...*.*****.*...*.*...*.");//H
	alph.push_back("*****...*.....*.....*...*****.");//I
	alph.push_back("..***....*.....*..*..*...**...");//J
	alph.push_back("*...*.*..*..***...*..*..*...*.");//K
	alph.push_back("*.....*.....*.....*.....*****.");//L
	alph.push_back("*...*.**.**.*.*.*.*...*.*...*.");//M
	alph.push_back("*...*.**..*.*.*.*.*..**.*...*.");//N
	alph.push_back(".***..*...*.*...*.*...*..***..");//O
	alph.push_back("****..*...*.****..*.....*.....");//P
	alph.push_back(".***..*...*.*...*.*..**..****.");//Q
	alph.push_back("****..*...*.****..*..*..*...*.");//R
	alph.push_back(".****.*......***......*.****..");//S
	alph.push_back("*****.*.*.*...*.....*....***..");//T
	alph.push_back("*...*.*...*.*...*.*...*..***..");//U
	alph.push_back("*...*.*...*..*.*...*.*....*...");//V
	alph.push_back("*...*.*...*.*.*.*.**.**.*...*.");//W
	alph.push_back("*...*..*.*....*....*.*..*...*.");//X
	alph.push_back("*...*..*.*....*.....*.....*...");//Y
	alph.push_back("*****....*....*....*....*****.");//Z
	//alph.push_back("");
	//alph.push_back("");
}
int main()
{
	f();
	string example;
	vector<string>list;
	string how;
	char sine;
	while (true)
	{
		bool f = true;
		//make field
		list.clear();
		for (size_t i = 0; i < 60; i++)
		{
			list.push_back(example);
			for (size_t j = 0; j < 60; j++)
			{
				list[i] += '.';
			}
		}
		bool fout = false;
		while (cin >> sine >> how)
		{
			f = false;
			if (how == "EOP")
			{
				fout = true;
				break;
			}
			//start input
			char font;
			cin >> font >> font;
			int line;
			cin >> line;
			int col;
			if (how == "P")
			{
				cin >> col;
			}
			cin.ignore();
			string str;
			getline(cin, str);
			str = strsaz(str);
			//end of input
			//processing
			if (font == '1')
			{
				if (how == "C")
				{
					//making index of string
					int my_index;
					if (str.length() % 2 == 0)
					{
						my_index = (str.length() - 1) / 2;
					}
					else
					{
						my_index = (str.length() - 2) / 2;
					}
					//mid to left
					for (int i = 0; i < 30; i++)
					{
						if (0 > (my_index - i))
						{
							break;
						}
						if (str[my_index - i]==' ')
						{
							continue;
						}
						list[line - 1][29 - i] = str[my_index - i];
					}
					//mid to right
					for (int i = 0; i < 30; i++)
					{
						if (my_index + 1 + i >= str.length())
						{
							break;
						}
						if (str[my_index + 1 + i]==' ')
						{
							continue;
						}
						list[line - 1][30 + i] = str[my_index + 1 + i];
					}
				}
				else if (how == "L")
				{
					//start to right
					for (int i = 0; i < 60; i++)
					{
						if (i >= str.length())
						{
							break;
						}
						if (str[i]==' ')
						{
							continue;
						}
						list[line - 1][i] = str[i];
					}
				}
				else if (how == "R")
				{
					//end to left
					for (int i = 0; i < 60; i++)
					{
						if (i >= str.length())
						{
							break;
						}
						if (str[str.length() - 1 - i] == ' ')
						{
							continue;
						}
						list[line - 1][59 - i] = str[str.length() - 1 - i];
					}
				}
				else if (how == "P")
				{
					//col to right
					int my_len = str.length();
					if (60-col<my_len)
					{
						my_len = 60 - col +1;
					}
					for (int i = 0; i < my_len; i++)
					{
						if (i >= str.length())
						{
							break;
						}
						if (str[i]==' ')
						{
							continue;
						}
						list[line - 1][i + col - 1] = str[i];
					}
				}
			}
			else
			{
				//making 5 string of this line
				vector<string>five;
				five.push_back(example);
				five.push_back(example);
				five.push_back(example);
				five.push_back(example);
				five.push_back(example);
				//
				for (size_t i = 0; i < str.length(); i++)
				{
					for (size_t j = 0; j < 5; j++)
					{
						if (str[i] == ' ')
						{
							five[j] += "......";
						}
						else
						{
							for (size_t z = 0; z < 6; z++)
							{

								five[j] += alph[str[i] - 'A'][j * 6 + z];
							}
						}
					}
				}
				//big font /making list
				if (how == "C")
				{
					//making index of string
					int my_index;
					if (five[0].length() % 2 == 0)
					{
						my_index = (five[0].length() - 1) / 2;
					}
					else
					{
						my_index = (five[0].length() - 2) / 2;
					}
					//mid to left
					for (size_t j = 0; j < 5; j++)
					{
						if (line - 1 + j >= 60)
						{
							break;
						}
						for (int i = 0; i < 30; i++)
						{
							if (0 > (my_index - i))
							{
								break;
							}
							if (five[j][my_index - i]=='.')
							{
								continue;
							}
							list[line - 1 + j][29 - i] = five[j][my_index - i];//five
						}
					}
					//mid to right
					for (size_t j = 0; j < 5; j++)
					{
						if (line - 1 + j >= 60)
						{
							break;
						}
						for (int i = 0; i < 30; i++)
						{
							if (my_index + 1 + i >= five[0].length())
							{
								break;
							}
							if (five[j][my_index + 1 + i]=='.')
							{
								continue;
							}
							list[line - 1 + j][30 + i] = five[j][my_index + 1 + i];//five
						}
					}
				}
				else if (how == "L")
				{
					int my_len = 60;
					if (my_len > five[0].length())
					{
						my_len = five[0].length();
					}
					for (size_t j = 0; j < 5; j++)
					{
						if (line - 1 + j >= 60)
						{
							break;
						}
						for (int i = 0; i < my_len; i++)
						{
							if (five[j][i]=='.')
							{
								continue;
							}
							list[line - 1 + j][i] = five[j][i];
						}
					}
				}
				else if (how == "R")
				{
					int my_len = 60;
					if (my_len > five[0].length())
					{
						my_len = five[0].length();
					}
					for (size_t j = 0; j < 5; j++)
					{
						if (line - 1 + j>=60)
						{
							break;
						}
						for (int i = 0; i < my_len; i++)
						{
							if ((five[0].length() - 1 - i)>=0)
							{
								if (five[j][five[0].length() - 1 - i]=='.')
								{
									continue;
								}
								list[line - 1 + j][59 - i] = five[j][five[0].length() - 1 - i];
							}
							else
							{
								break;
							}
						}
					}
				}
				else if (how == "P")
				{
					int my_len = 60;
					if (my_len > five[0].length())
					{
						my_len = five[0].length();
					}
					for (size_t j = 0; j < 5; j++)
					{
						if (line - 1 + j >= 60)
						{
							break;
						}
						for (int i = 0; i < my_len; i++)
						{
							if (col + i - 1 < 60)
							{
								if (five[j][i]=='.')
								{
									continue;
								}
								list[line - 1 + j][col + i - 1] = five[j][i];
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
		if (f)
		{
			break;
		}
		//output
		if (fout)
		{
			for (size_t i = 0; i < 60; i++)
			{
				cout << list[i] << endl;
			}
			cout << endl;
			for (size_t i = 0; i < 60; i++)
			{
				cout << "-";
			}
			cout << endl << endl;
		}
	}
}
