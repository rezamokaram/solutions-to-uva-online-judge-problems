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
int retv(string str)
{
	if (str[1] == 'A')
	{
		return 14;
	}
	else if (str[1] == 'K')
	{
		return 13;
	}
	else if (str[1] == 'Q')
	{
		return 12;
	}
	else if (str[1] == 'J')
	{
		return 11;
	}
	else if (str[1] == 'T')
	{
		return 10;
	}
	int res = (str[1] - '0');
	return res;
}
bool isf(string str)
{
	if (str[1] == 'A' || str[1] == 'K')
	{
		return 1;
	}
	if (str[1] == 'Q' || str[1] == 'J')
	{
		return 1;
	}
	return 0;
}
int main()
{
	string a;
	while (cin >> a)
	{
		if (a == "#")
		{
			break;
		}
		deque<string>non, del, deck;
		bool turn = 1;
		non.push_front(a);
		for (size_t i = 0; i < 51; i++)
		{
			cin >> a;
			if (i % 2 == 0)
			{
				del.push_front(a);
			}
			else
			{
				non.push_front(a);
			}
		}
		//
		int nt = 0;
		while (true)
		{
			if ((non.empty() && turn) || (!turn && del.empty()))
				break;
			if (turn)
			{
				string th = non.front();
				deck.push_front(th);
				non.pop_front();
				//
				if (isf(th))
				{
					turn = 0;
					nt = retv(th) - 10;
					continue;
				}
				//
				if (nt > 0)
				{
					if (nt == 1)
					{
						nt = 0;
						while (!deck.empty())
						{
							del.push_back(deck.back());
							deck.pop_back();
						}
						turn = 0;
					}
					else
					{
						nt--;
					}
				}
				else
				{
					turn = 0;
				}
			}
			else
			{
				string th = del.front();
				deck.push_front(th);
				del.pop_front();
				//
				if (isf(th))
				{
					turn = 1;
					nt = retv(th) - 10;
					continue;
				}
				//
				if (nt > 0)
				{
					if (nt == 1)
					{
						nt = 0;
						while (!deck.empty())
						{
							non.push_back(deck.back());
							deck.pop_back();
						}
						turn = 1;
					}
					else
					{
						nt--;
					}
				}
				else
				{
					turn = 1;
				}
			}
		}
		if (non.size() == 0) {
			cout << 1;
			if (del.size() < 100)
			{
				cout << " ";
			}
			if (del.size() < 10)
			{
				cout << " ";
			}
			cout << del.size() << endl;
		}
		else {
			cout << 2 ;
			if (non.size()<100)
			{
				cout << " ";
			}
			if (non.size() < 10)
			{
				cout << " ";
			}
			cout << non.size() << endl;
		}
	}
}
