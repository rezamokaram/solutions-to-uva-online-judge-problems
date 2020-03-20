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
vector<string>maze;
vector<vector<int>>visit;
char jahat = 'r';
int nx = 0;
int ny = 0;
//
bool invalid_loc(int x, int y)
{
	if (x < maze.size() && y < maze[0].length())
	{
		if (maze[x][y] != '1')
		{
			return true;
		}
	}
	return false;
}
//
void tout(int number)
{
	if (number<10)
	{
		cout << "  ";
	}
	else if (number<100)
	{
		cout << " ";
	}
	cout << number;
}
//
char best_jahat()
{
	if (jahat=='r')
	{
		if (invalid_loc(nx+1,ny))
		{
			return 'd';
		}
		else if (invalid_loc(nx, ny + 1))
		{
			return 'r';
		}
		else if (invalid_loc(nx - 1, ny))
		{
			return 't';
		}
		else if (invalid_loc(nx, ny - 1))
		{
			return 'l';
		}
	}
	else if (jahat=='t')
	{
		if (invalid_loc(nx, ny+1))
		{
			return 'r';
		}
		else if (invalid_loc(nx-1, ny))
		{
			return 't';
		}
		else if (invalid_loc(nx, ny-1))
		{
			return 'l';
		}
		else if (invalid_loc(nx+1, ny))
		{
			return 'd';
		}
	}
	else if (jahat=='l')
	{
		if (invalid_loc(nx-1, ny))
		{
			return 't';
		}
		else if (invalid_loc(nx, ny-1))
		{
			return 'l';
		}
		else if (invalid_loc(nx+1, ny))
		{
			return 'd';
		}
		else if (invalid_loc(nx, ny+1))
		{
			return 'r';
		}
	}
	else if (jahat=='d')
	{
		if (invalid_loc(nx, ny - 1))
		{
			return 'l';
		}
		else if (invalid_loc(nx + 1, ny))
		{
			return 'd';
		}
		else if (invalid_loc(nx, ny + 1))
		{
			return 'r';
		}
		else if (invalid_loc(nx - 1, ny))
		{
			return 't';
		}
	}
	else
	{
		return 'r';
	}
	return 'r';
}
int main()
{
	int x, y;
	while (cin >> x >> y && x && y)
	{
		cin.ignore();
		maze.clear();
		visit.clear();
		for (size_t i = 0; i < x; i++)
		{
			string temp;
			getline(cin, temp);
			maze.push_back(temp);
			vector<int>lol;
			visit.push_back(lol);
			for (size_t j = 0; j < y; j++)
			{
				if (maze[i][j]=='1')
				{
					visit[i].push_back(-1);
				}
				else
				{
					visit[i].push_back(0);
				}
			}
		}
		//process
		jahat = 't';
		nx = x - 1;
		ny = 0;
		jahat = best_jahat();
		do
		{
			if (jahat=='r')
			{
				if (invalid_loc(nx,ny+1))
				{
					ny++;
					visit[nx][ny]++;
				}
			}
			else if (jahat=='t')
			{
				if (invalid_loc(nx-1, ny))
				{
					nx--;
					visit[nx][ny]++;
				}
			}
			else if (jahat == 'l')
			{
				if (invalid_loc(nx, ny - 1))
				{
					ny--;
					visit[nx][ny]++;
				}
			}
			else if (jahat=='d')
			{
				if (invalid_loc(nx+1, ny))
				{
					nx++;
					visit[nx][ny]++;
				}
			}
			jahat = best_jahat();
		} while (nx != x - 1 || ny != 0);
		//end process
		int a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
		for (size_t i = 0; i < x; i++)
		{
			for (size_t j = 0; j < y; j++)
			{
				if (visit[i][j]==0)
				{
					a0++;
				}
				else if (visit[i][j]==1)
				{
					a1++;
				}
				else if (visit[i][j] == 2)
				{
					a2++;
				}
				else if (visit[i][j] == 3)
				{
					a3++;
				}
				else if (visit[i][j] == 4)
				{
					a4++;
				}
				else
				{
					continue;
				}

			}
			
		}
		tout(a0);
		tout(a1);
		tout(a2);
		tout(a3);
		tout(a4);
		cout << endl;
	}
}
