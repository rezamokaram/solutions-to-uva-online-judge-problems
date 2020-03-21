#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	int a, b;
	for (int z=1;cin >>a>>b;z++)
	{
		if (a==0 || b==0)
		{
			break;
		}
		else
		{
			if (z > 1)
			{
				cout << endl;
			}
			char filds[101][101],arr[101][101];
			for (size_t i = 0; i < a; i++)
			{
				cin >> filds[i];
			}
			for (size_t i = 0; i < a; i++)
			{
				for (size_t j = 0; j < b; j++)
				{
					if (filds[i][j]=='*')
					{
						arr[i][j] = '*';
					}
					else
					{
						
						int counter = 0;
						if (j>0 && filds[i][j-1]=='*')
						{
							counter++;
						}
						if (j < b-1 && filds[i][j + 1] == '*')
						{
							counter++;
						}
						if (i > 0)
						{
							if (filds[i-1][j]=='*')
							{
								counter++;
							}
							if (filds[i - 1][j + 1] == '*' && j < b - 1)
							{
								counter++;
							}
							if (filds[i - 1][j - 1] == '*' && j > 0)
							{
								counter++;
							}
						}
						if (i < a-1)
						{
							if (filds[i + 1][j] == '*')
							{
								counter++;
							}
							if (filds[i + 1][j + 1] == '*' && j< b-1)
							{
								counter++;
							}
							if (filds[i + 1][j - 1] == '*' && j>0)
							{
								counter++;
							}
						}
						arr[i][j] = '0' + counter;
					}
				}
			}
			cout << "Field #" << z << ":\n";
			for (size_t i = 0; i < a; i++)
			{
				for (size_t j = 0; j < b; j++)
				{
					cout << arr[i][j];
				}
				cout << endl;
			}
			
		}
	}
}
