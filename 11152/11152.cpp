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
#include <map>
#include <set>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
double arr[3] = { 0 };
void out(double a)
{
	cout << fixed << setprecision(4) << a;
}
double const pi = acos(-1);// 3.14159265458979;
int main()
{
	while (cin >> arr[0] >> arr[1] >> arr[2])
	{
		sort(arr, arr + 3);
		double p = arr[0] + arr[1] + arr[2];
		p /= 2.0;
		double area_triangl = sqrt((double)p*(p - arr[0])*(p - arr[1])*(p - arr[2]));
		double r = area_triangl * 2.0 / (arr[0] + arr[1] + arr[2]);
		double R = (arr[0] * arr[1] * arr[2] / 4.0) / area_triangl;
		//double area_little_circul = r * r * pi;
		//double area_big_circle = pi * arr[2] * arr[2] / 4.0;
		double area_big_circle = R * R*pi;
		double area_little_circul = pi * (area_triangl / p) * (area_triangl / p);
		//output
		out(area_big_circle - area_triangl);
		cout << " ";
		out(area_triangl - area_little_circul);
		cout << " ";
		out(area_little_circul);
		cout << endl;
	}
}
