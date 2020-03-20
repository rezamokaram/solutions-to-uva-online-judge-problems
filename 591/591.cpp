#include <iostream>
using namespace std;
int sumARR(int list[],int size)
{
	int sum = 0;
	for (size_t i = 0; i < size ; i++)
	{
		sum += list[i];
	}
	return sum;
}
int numberOFmoves(int list[],int size, int avrg)
{
	int moves = 0;
	for (size_t i = 0; i < size ; i++)
	{
		if (list[i]>avrg)
		{
			moves += list[i] - avrg;
		}
	}
	return moves;
}
int main()
{
	int arr[1000],n;
	for (int z=1;cin >> n;z++)
	{
		if (n==0)
		{
			break;
		}
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int avrg = sumARR(arr,n) / n;
		cout <<"Set #"<<z<< "\nThe minimum number of moves is " << numberOFmoves(arr,n, avrg) << ".\n\n";
	}
	system("pause>A");
}
