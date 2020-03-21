#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <functional>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
bool invalid_loc(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
//
int main()
{
	string temp;
	int game = 0;
	while (cin >> temp)
	{
		if (temp == "")break;
		game++;
		vector<string>list(8);
		list[0] = temp;
		int bbr = 0;
		if (temp == "........")
		{
			bbr++;
		}
		for (size_t i = 1; i < 8; i++)
		{
			cin >> list[i];
			if (list[i] == "........")
			{
				bbr++;
			}
		}
		if (bbr == 8)
		{
			break;
		}
		int br = 0;
		bool f = 0, F = 0;
		bool f1 = 1, f2 = 1, f3 = 1, f4 = 1, f5 = 1, f6 = 1, f7 = 1, f8 = 1;
		bool F1 = 1, F2 = 1, F3 = 1, F4 = 1, F5 = 1, F6 = 1, F7 = 1, F8 = 1;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (list[i][j] == 'k' || list[i][j] == 'K')
				{
					br++;
					if (list[i][j] == 'k')
					{
						if (i<7)
						{
							if (j<7)
							{
								if (list[i + 1][j + 1] == 'P')
								{
									f = 1;
									break;
								}
							}
							if (j>0)
							{
								if (list[i + 1][j - 1] == 'P')
								{
									f = 1;
									break;
								}
							}
						}
						if (invalid_loc(i-2,j-1))
						{
							if (list[i-2][j-1] == 'N')
							{
								f = 1; 
								break;
							}
						}
						if (invalid_loc(i - 2, j + 1))
						{
							if (list[i - 2][j + 1] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i + 2, j - 1))
						{
							if (list[i + 2][j - 1] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i + 2, j + 1))
						{
							if (list[i + 2][j + 1] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i - 1, j - 2))
						{
							if (list[i - 1][j - 2] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i - 1, j + 2))
						{
							if (list[i - 1][j + 2] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i + 1, j - 2))
						{
							if (list[i + 1][j - 2] == 'N')
							{
								f = 1;
								break;
							}
						}
						if (invalid_loc(i + 1, j + 2))
						{
							if (list[i + 1][j + 2] == 'N')
							{
								f = 1;
								break;
							}
						}
						int x = i, y = j;
						for (int z = 1; z < 8; z++)
						{
							if (invalid_loc(x - z, y - z))
							{
								if ((list[x - z][y - z] == 'B' || list[x - z][y - z] == 'Q' )&& f1)
								{
									f = 1;
									break;
								}
								if (list[x-z][y-z]!='.')
								{
									f1 = 0;
								}
							}
							if (invalid_loc(x + z, y - z))
							{
								if ((list[x + z][y - z] == 'B' || list[x + z][y - z] == 'Q') && f2)
								{
									f = 1;
									break;
								}
								if (list[x + z][y - z] != '.')
								{
									f2 = 0;
								}
							}
							if (invalid_loc(x - z, y + z))
							{
								if ((list[x - z][y + z] == 'B' || list[x - z][y + z] == 'Q' )&& f3)
								{
									f = 1;
									break;
								}
								if (list[x - z][y + z] != '.')
								{
									f3 = 0;
								}
							}
							if (invalid_loc(x + z, y + z))
							{
								if ((list[x + z][y + z] == 'B' || list[x + z][y + z] == 'Q') && f4)
								{
									f = 1;
									break;
								}
								if (list[x + z][y + z] != '.')
								{
									f4 = 0;
								}
							}
							//end of bishop and queen
							// start rook and queen
							if (invalid_loc(x, y - z))
							{
								if ((list[x][y - z] == 'R' || list[x][y - z] == 'Q' )&& f5)
								{
									f = 1;
									break;
								}
								if (list[x][y - z] != '.')
								{
									f5 = 0;
								}
							}
							if (invalid_loc(x, y + z))
							{
								if ((list[x][y + z] == 'R' || list[x][y + z] == 'Q') && f6)
								{
									f = 1;
									break;
								}
								if (list[x][y + z] != '.')
								{
									f6 = 0;
								}
							}
							if (invalid_loc(x - z, y))
							{
								if ((list[x - z][y] == 'R' || list[x - z][y] == 'Q') && f7)
								{
									f = 1;
									break;
								}
								if (list[x - z][y] != '.')
								{
									f7 = 0;
								}
							}
							if (invalid_loc(x + z, y))
							{
								if ((list[x + z][y] == 'R' || list[x + z][y] == 'Q') && f8)
								{
									f = 1;
									break;
								}
								if (list[x + z][y] != '.')
								{
									f8 = 0;
								}
							}
						}
						if (f)
						{
							break;
						}

					}
					else if(list[i][j]=='K')
					{
						if (i>0)
						{
							if (j>0)
							{
								if (list[i - 1][j - 1] == 'p')
								{
									F = 1;
									break;
								}
							}
							if (j<7)
							{
								if (list[i - 1][j + 1] == 'p')
								{
									F = 1;
									break;
								}
							}
						}
						//
						if (invalid_loc(i - 2, j - 1))
						{
							if (list[i - 2][j - 1] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i - 2, j + 1))
						{
							if (list[i - 2][j + 1] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i + 2, j - 1))
						{
							if (list[i + 2][j - 1] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i + 2, j + 1))
						{
							if (list[i + 2][j + 1] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i - 1, j - 2))
						{
							if (list[i - 1][j - 2] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i - 1, j + 2))
						{
							if (list[i - 1][j + 2] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i + 1, j - 2))
						{
							if (list[i + 1][j - 2] == 'n')
							{
								F = 1;
								break;
							}
						}
						if (invalid_loc(i + 1, j + 2))
						{
							if (list[i + 1][j + 2] == 'n')
							{
								F = 1;
								break;
							}
						}
						//
						int x = i, y = j;
						for (int z = 1; z < 8; z++)
						{
							if (invalid_loc(x - z, y - z))
							{
								if ((list[x - z][y - z] == 'b' || list[x - z][y - z] == 'q') && F1)
								{
									F = 1;
									break;
								}
								if (list[x - z][y - z] != '.')
								{
									F1 = 0;
								}
							}
							if (invalid_loc(x + z, y - z))
							{
								if ((list[x + z][y - z] == 'b' || list[x + z][y - z] == 'q') && F2)
								{
									F = 1;
									break;
								}
								if (list[x + z][y - z] != '.')
								{
									F2 = 0;
								}
							}
							if (invalid_loc(x - z, y + z))
							{
								if ((list[x - z][y + z] == 'b' || list[x - z][y + z] == 'q') && F3)
								{
									F = 1;
									break;
								}
								if (list[x - z][y + z] != '.')
								{
									F3 = 0;
								}
							}
							if (invalid_loc(x + z, y + z))
							{
								if ((list[x + z][y + z] == 'b' || list[x + z][y + z] == 'q') && F4)
								{
									F = 1;
									break;
								}
								if (list[x + z][y + z] != '.')
								{
									F4 = 0;
								}
							}
							//end of bishop and queen
							// start rook and queen
							if (invalid_loc(x, y - z))
							{
								if ((list[x][y - z] == 'r' || list[x][y - z] == 'q') && F5)
								{
									F = 1;
									break;
								}
								if (list[x][y - z] != '.')
								{
									F5 = 0;
								}
							}
							if (invalid_loc(x, y + z))
							{
								if ((list[x][y + z] == 'r' || list[x][y + z] == 'q') && F6)
								{
									F = 1;
									break;
								}
								if (list[x][y + z] != '.')
								{
									F6 = 0;
								}
							}
							if (invalid_loc(x - z, y))
							{
								if ((list[x - z][y] == 'r' || list[x - z][y] == 'q') && F7)
								{
									F = 1;
									break;
								}
								if (list[x - z][y] != '.')
								{
									F7 = 0;
								}
							}
							if (invalid_loc(x + z, y))
							{
								if ((list[x + z][y] == 'r' || list[x + z][y] == 'q') && F8)
								{
									F = 1;
									break;
								}
								if (list[x + z][y] != '.')
								{
									F8 = 0;
								}
							}
						}
						if (F)
						{
							break;
						}
					}
				}
				if (br >= 2 || f || F)
					break;
			}
			if (br >= 2 || f || F)
				break;
		}
		cout << "Game #" << game << ": ";
		if (f)
		{
			cout << "black king is in check." << endl;
		}
		else if (F)
		{
			cout << "white king is in check." << endl;
		}
		else
		{
			cout << "no king is in check." << endl;
		}
	}
}
