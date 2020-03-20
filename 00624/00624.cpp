#include <iostream>
#include <string>
//#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
int nsum = 0;
int nelement[20] = { 0 };
int element[20] = { 0 };
vector <int>arr;
int maxsum;
void bt(  int size, int index,int sum)
{
	if (sum > maxsum)
	{
		return;
	}
	if (sum<=maxsum && sum>nsum)
	{
		nsum = sum;
		for (size_t q = 0; q < 20; q++)
		{
			nelement[q] = element[q];
		}
	}
	if (sum==maxsum)
	{
		return;
	}
	if (index>=size)
	{
		return;
	}
	//
	
	element[index] = 1;
	bt( size, index + 1, sum + arr[index]);
	element[index] = 0;
	bt(size, index + 1, sum);
}

int main()
{
	while (cin >> maxsum)
	{
		int size;
		cin >> size;
		arr.clear();
		for (size_t i = 0; i < size; i++)
		{
			int d;
			cin >> d;
			arr.push_back(d);
		}
		//
		nsum = 0;
		for (size_t q = 0; q < 20; q++)
		{
			element[q] = 0;
			nelement[q] = 0;
		}
		bt( size, 0,0);
		for (size_t i = 0; i < sizeof(nelement) ; i++)
		{
			if (i < size   && nelement[i] == 1)
			{
				cout << arr[i] << " ";
			}
		}
		cout << "sum:" << nsum << endl;
	}
}
