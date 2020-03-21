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
vector<string>list;
void f()
{
	list.push_back("2 of Clubs");
	list.push_back("3 of Clubs");
	list.push_back("4 of Clubs");
	list.push_back("5 of Clubs");
	list.push_back("6 of Clubs");
	list.push_back("7 of Clubs");
	list.push_back("8 of Clubs");
	list.push_back("9 of Clubs");
	list.push_back("10 of Clubs");
	list.push_back("Jack of Clubs");
	list.push_back("Queen of Clubs");
	list.push_back("King of Clubs");
	list.push_back("Ace of Clubs");
	list.push_back("2 of Diamonds");
	list.push_back("3 of Diamonds");
	list.push_back("4 of Diamonds");
	list.push_back("5 of Diamonds");
	list.push_back("6 of Diamonds");
	list.push_back("7 of Diamonds");
	list.push_back("8 of Diamonds");
	list.push_back("9 of Diamonds");
	list.push_back("10 of Diamonds");
	list.push_back("Jack of Diamonds");
	list.push_back("Queen of Diamonds");
	list.push_back("King of Diamonds");
	list.push_back("Ace of Diamonds");
	list.push_back("2 of Hearts");
	list.push_back("3 of Hearts");
	list.push_back("4 of Hearts");
	list.push_back("5 of Hearts");
	list.push_back("6 of Hearts");
	list.push_back("7 of Hearts");
	list.push_back("8 of Hearts");
	list.push_back("9 of Hearts");
	list.push_back("10 of Hearts");
	list.push_back("Jack of Hearts");
	list.push_back("Queen of Hearts");
	list.push_back("King of Hearts");
	list.push_back("Ace of Hearts");
	list.push_back("2 of Spades");
	list.push_back("3 of Spades");
	list.push_back("4 of Spades");
	list.push_back("5 of Spades");
	list.push_back("6 of Spades");
	list.push_back("7 of Spades");
	list.push_back("8 of Spades");
	list.push_back("9 of Spades");
	list.push_back("10 of Spades");
	list.push_back("Jack of Spades");
	list.push_back("Queen of Spades");
	list.push_back("King of Spades");
	list.push_back("Ace of Spades");
}
vector<int>shufl(52);
int main()
{
	f();
	int tc;
	cin >> tc;
	while (tc--)
	{
		int s;
		cin >> s;
		vector<vector<int>>ml;
		int index = 0;
		while (s--)
		{
			ml.push_back(shufl);
			for (size_t i = 0; i < 52; i++)
			{
				cin >> ml[index][i];
			}
			index++;
		}
		vector<int>last;
		cin.ignore();
		string new_index;
		while (getline(cin,new_index))
		{
			if (new_index=="")
			{
				break;
			}
			last.push_back(stoi(new_index) - 1);
		}
		for (size_t i = 0; i < 52; i++)
		{
			int card = i;
			for (int j = last.size() - 1; j >= 0; j--)
			{
				card = ml[last[j]][card]-1;
			}
			cout << list[card] << endl;
		}
		if (tc)
		{
			cout << endl;
		}
	}
}
