#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

//using namespace std;
typedef long long unsigned int ll;

int main()
{
	double a, b;
	while (scanf("%lf\n%lf", &a,&b) != EOF )
	{
		double temp = pow(b, 1.0 / a);
	    printf( "%.0lf\n", temp );
	}
}
