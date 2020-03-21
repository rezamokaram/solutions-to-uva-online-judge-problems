#include <iostream>
#include <string>
#include <algorithm>
//#include <ctring>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		int coco = 0;
		while (n>=3)
		{
			n -= 3;
			coco++;
			n++;
		}
		if (n==2)
		{
			coco++;
		}
		cout << coco << endl;
	}
}
