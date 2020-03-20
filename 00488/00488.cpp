/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << "\n";
	for (size_t i = 0; i < n; i++)
	{
		int number, hight;
		cin >> hight;
		cin >> number;
		cout << "\n";
		for (size_t j = 0; j < number; j++)
		{
			for (size_t z = 1; z <= hight; z++)
			{
				for (size_t q = 0; q < z; q++)
				{
					cout << z;
				}
				cout << "\n";
			}
			for (size_t z = hight-1; z > 0; z--)
			{
				for (size_t q = 0; q < z; q++)
				{
					cout << z;
				}
				cout << "\n";
			}
			if (j <(number - 1))
			{
				cout << "\n";
			}
		}
		//if (i <(n - 1))
		//{
		   cout << "\n";
		//}

	}
	system("pause>A");
}*/
#include <cstdio>
#include <stdio.h>
using namespace std;
int main() {

	int tc, f, a;



	scanf("%d", &tc);

	while (tc--) {

		scanf("%d\n%d", &a, &f);



		for (int i = 0; i < f; i++) {

			for (int j = 1; j <= a; j++) {

				for (int k = 0; k < j; k++) {

					printf("%d", j);

				}

				printf("\n");

			}

			for (int j = a - 1; j >= 1; j--) {

				for (int k = 0; k < j; k++) {

					printf("%d", j);

				}

				printf("\n");

			}

			if (i != f - 1)

				printf("\n");

		}

		if (tc)

			printf("\n");

	}



	return 0;

}
