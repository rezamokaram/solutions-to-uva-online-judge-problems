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
	string chess;
	while (cin >> chess)
	{
		vector<string>chart;
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		chart.push_back("........");
		//making chart
		int line = 0;
		int length = 0;
		for (size_t i = 0; i < chess.length(); i++)
		{
			if (chess[i] == '/')
			{
				line++;
				length = 0;
			}
			else if (chess[i] >= '0' && chess[i] <='9')
			{
				length += chess[i] - '0';
			}
			else
			{
				chart[line][length] = chess[i];
				length++;
			}
		}
	    //
		// process
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				//knights
				if (chart[i][j] == 'n' || chart[i][j] == 'N')
				{
					//i
					if ((i + 2) < 8 && (j + 1) < 8)
					{
						if (chart[i + 2][j + 1] == '.')
						{
							chart[i + 2][j + 1] = '*';
						}
					}
					if ((i + 2) < 8 && (j - 1) >= 0)
					{
						if (chart[i + 2][j - 1] == '.')
						{
							chart[i + 2][j - 1] = '*';
						}
					}
					if ((i - 2) >= 0 && (j + 1) < 8)
					{
						if (chart[i - 2][j + 1] == '.')
						{
							chart[i - 2][j + 1] = '*';
						}
					}
					if (i - 2 >= 0 && j - 1 >= 0)
					{
						if (chart[i - 2][j - 1] == '.')
						{
							chart[i - 2][j - 1] = '*';
						}
					}
					//j
					if (i + 1 < 8 && j + 2 < 8)
					{
						if (chart[i + 1][j + 2] == '.')
						{
							chart[i + 1][j + 2] = '*';
						}
					}
					if (i - 1 >= 0 && j + 2 < 8)
					{
						if (chart[i - 1][j + 2] == '.')
						{
							chart[i - 1][j + 2] = '*';
						}					
					}
					if (i + 1 < 8 && j - 2 >= 0)
					{
						if (chart[i + 1][j - 2] == '.')
						{
							chart[i + 1][j - 2] = '*';
						}
					}
					if (i - 1 >= 0 && j - 2 >= 0)
					{
						if (chart[i - 1][j - 2] == '.')
						{
							chart[i - 1][j - 2] = '*';
						}					
					}
				}
				//pawn w
				else if (chart[i][j] == 'P')
				{
					if (i - 1 >= 0 && j + 1 < 8)
					{
						if (chart[i - 1][j + 1] == '.')
						{
							chart[i - 1][j + 1] = '*';
						}
					}
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if (chart[i - 1][j - 1] == '.')
						{
							chart[i - 1][j - 1] = '*';
						}
					}
				}
				//pawn b
				else if (chart[i][j] == 'p')
				{
					if (i + 1 < 8 && j + 1 < 8)
					{
						if (chart[i + 1][j + 1] == '.')
						{
							chart[i + 1][j + 1] = '*';
						}
					}
					if (i + 1 < 8 && j - 1 >= 0)
					{
						if (chart[i + 1][j - 1] == '.')
						{
							chart[i + 1][j - 1] = '*';
						}
					}
				}
				//kings
				else if (chart[i][j] == 'k' || chart[i][j] == 'K')
				{
					//1
					if (j + 1 < 8)
					{
						if (chart[i][j + 1] == '.')
						{
							chart[i][j + 1] = '*';
						}
					}
					if (j - 1 >= 0)
					{
						if (chart[i][j - 1] == '.')
						{
							chart[i][j - 1] = '*';
						}
					}
					if (i + 1 < 8)
					{
						if (chart[i + 1][j] == '.')
						{
							chart[i + 1][j] = '*';
						}
					}
					if (i - 1 >= 0)
					{
						if (chart[i - 1][j] == '.')
						{
							chart[i - 1][j] = '*';
						}
					}
					//2
					if (i + 1 < 8 && j + 1 < 8)
					{
						if (chart[i + 1][j + 1] == '.')
						{
							chart[i + 1][j + 1] = '*';
						}
					}
					if (i + 1 < 8 && j - 1 >= 0)
					{
						if (chart[i + 1][j - 1] == '.')
						{
							chart[i + 1][j - 1] = '*';
						}
					}
					if (i - 1 >= 0 && j + 1 < 8)
					{
						if (chart[i - 1][j + 1] == '.')
						{
							chart[i - 1][j + 1] = '*';
						}
					}
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if (chart[i - 1][j - 1] == '.')
						{
							chart[i - 1][j - 1] = '*';
						}
					}
				}
				//rooks
				else if (chart[i][j] == 'r' || chart[i][j] == 'R')
				{
				    //i
					for (int z = 1; z < 8; z++)
					{
						if (i+z>=8)
						{
							break;
						}
						if (i + z < 8 && chart[i + z][j] == '.' || chart[i + z][j] == '*')
						{
							chart[i + z][j] = '*';
						}
						else
						{
							break;
						}
					}
					for (int z = 1; z < 8; z++)
					{
						if (z > i)
						{
							break;
						}
						if (i - z >= 0 && (chart[i - z][j] == '.' || chart[i - z][j] == '*'))
						{
							chart[i - z][j] = '*';
						}
						else
						{
							break;
						}
					}
					//j
					for (int z = 1; z < 8; z++)
					{
						if (j+z>=8)
						{
							break;
						}
						if (j + z < 8 && chart[i][j + z] == '.' || chart[i][j + z] == '*')
						{
							chart[i][j + z] = '*';
						}
						else
						{
							break;
						}
					}
					for (int z = 1; z < 8; z++)
					{
						if (z>j)
						{
							break;
						}
						if (j - z >= 0 && chart[i][j - z] == '.' || chart[i][j - z] == '*')
						{
							chart[i][j - z] = '*';
						}
						else
						{
							break;
						}
					}
				}
				//bishops
				else if (chart[i][j] == 'b' || chart[i][j] == 'B')
				{
				for (int z = 1; z < 8; z++)
				{
					if (z+i >= 8 || z+j >=8)
					{
						break;
					}
					if (i + z < 8 && j + z < 8 && chart[i + z][j + z] == '.' || chart[i + z][j + z] == '*')
					{
						chart[i + z][j + z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (i+z>=8 || z>j)
					{
						break;
					}
					if (i + z < 8 && j - z >= 0 && chart[i + z][j - z] == '.' || chart[i + z][j - z] == '*')
					{
						chart[i + z][j - z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (i<z || j+z>=8)
					{
						break;
					}
					if (i - z >= 0 && j + z < 8 && chart[i - z][j + z] == '.' || chart[i - z][j + z] == '*')
					{
						chart[i - z][j + z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (z>i || z>j)
					{
						break;
					}
					if (i - z >= 0 && j - z >= 0 && chart[i - z][j - z] == '.' || chart[i - z][j - z] == '*')
					{
						chart[i - z][j - z] = '*';
					}
					else
					{
						break;
					}
				}
				}
				//quins
				else if (chart[i][j] == 'q' || chart[i][j] == 'Q')
	            {
				//from bishop
				for (int z = 1; z < 8; z++)
				{
					if (z + i >= 8 || z + j >= 8)
					{
						break;
					}
					if (i + z < 8 && j + z < 8 && chart[i + z][j + z] == '.' || chart[i + z][j + z] == '*')
					{
						chart[i + z][j + z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (i + z >= 8 || z > j)
					{
						break;
					}
					if (i + z < 8 && j - z >= 0 && chart[i + z][j - z] == '.' || chart[i + z][j - z] == '*')
					{
						chart[i + z][j - z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (i < z || j + z >= 8)
					{
						break;
					}
					if (i - z >= 0 && j + z < 8 && chart[i - z][j + z] == '.' || chart[i - z][j + z] == '*')
					{
						chart[i - z][j + z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (z > i || z > j)
					{
						break;
					}
					if (i - z >= 0 && j - z >= 0 && chart[i - z][j - z] == '.' || chart[i - z][j - z] == '*')
					{
						chart[i - z][j - z] = '*';
					}
					else
					{
						break;
					}
				}
				//from rook
				 //i
				for (int z = 1; z < 8; z++)
				{
					if (i + z >= 8)
					{
						break;
					}
					if (i + z < 8 && chart[i + z][j] == '.' || chart[i + z][j] == '*')
					{
						chart[i + z][j] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (z > i)
					{
						break;
					}
					if (i - z >= 0 && (chart[i - z][j] == '.' || chart[i - z][j] == '*'))
					{
						chart[i - z][j] = '*';
					}
					else
					{
						break;
					}
				}
				//j
				for (int z = 1; z < 8; z++)
				{
					if (j + z >= 8)
					{
						break;
					}
					if (j + z < 8 && chart[i][j + z] == '.' || chart[i][j + z] == '*')
					{
						chart[i][j + z] = '*';
					}
					else
					{
						break;
					}
				}
				for (int z = 1; z < 8; z++)
				{
					if (z > j)
					{
						break;
					}
					if (j - z >= 0 && chart[i][j - z] == '.' || chart[i][j - z] == '*')
					{
						chart[i][j - z] = '*';
					}
					else
					{
						break;
					}
				}
	            }
			}
		}
		//making answer
		int ans = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (chart[i][j]=='.')
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
		chart.clear();
	}
}
