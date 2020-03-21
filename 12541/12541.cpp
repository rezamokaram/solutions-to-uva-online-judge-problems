#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;


int main()
{
	int tc;
	while (cin >> tc)
	{
		vector<string>listname;
		int arr[100][3];
		int ary[100][3];
		int aryy[100][3];
		//cin
		for (size_t i = 0; i < tc; i++)
		{
			string name;
			cin >> name;
			listname.push_back(name);
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			ary[i][0] = arr[i][0];
			ary[i][1] = arr[i][1];
			ary[i][2] = arr[i][2];
			aryy[i][0] = arr[i][0];
			aryy[i][1] = arr[i][1];
			aryy[i][2] = arr[i][2];
		}
		//maxzone
		//year
		int nmax = -1;
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][2] > nmax)
			{
				nmax = ary[i][2];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][2] < nmax)
			{
				ary[i][2] = -1;
			}
		}
		//month
		nmax = -1;
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][2] < 0)
			{
				continue;
			}
			if (ary[i][1] > nmax)
			{
				nmax = ary[i][1];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][1] < nmax)
			{
				ary[i][1] = -1;
			}
		}
		//day
		nmax = -1;
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][2] < 0 || ary[i][1] < 0)
			{
				continue;
			}
			if (ary[i][0] > nmax)
			{
				nmax = ary[i][0];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][0] < nmax)
			{
				ary[i][0] = -1;
			}
		}
		//find
		int indexmax = 0;
		for (size_t i = 0; i < tc; i++)
		{
			if (ary[i][0] > 0 && ary[i][1] > 0 && ary[i][2] > 0)
			{
				indexmax = i;
				break;

			}
		}
		//
		//minzone
		//year
		int nmin = 111111;
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][2] < nmin)
			{
				nmin = aryy[i][2];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][2] > nmin)
			{
				aryy[i][2] = -1;
			}
		}
		//month
		nmin = 111111;
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][2] < 0)
			{
				continue;
			}
			if (aryy[i][1] < nmin)
			{
				nmin = aryy[i][1];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][1] > nmin)
			{
				aryy[i][1] = -1;
			}
		}
		//day
		nmin = 111111;
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][2] < 0 || aryy[i][1] < 0)
			{
				continue;
			}
			if (aryy[i][0] < nmin)
			{
				nmin = aryy[i][0];
			}
		}
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][0] > nmin)
			{
				aryy[i][0] = -1;
			}
		}
		//find
		int indexmin = 0;
		for (size_t i = 0; i < tc; i++)
		{
			if (aryy[i][0] > 0 && aryy[i][1] > 0 && aryy[i][2] > 0)
			{
				indexmin = i;
				break;
			}
		}
		//cout
		cout << listname[indexmax] << endl << listname[indexmin] << endl;
	}
}
