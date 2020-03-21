#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
class submit
{
public:
	submit(bool how,int ttime,int nqu);
	~submit();

	bool type;
	int time;
	int qu;
private:
	
};

submit::submit(bool how,int ttime,int nqu)
{
	time = ttime;
	type = how;
	qu = nqu;
}

submit::~submit()
{
}
//
class team
{
public:
	team();
	~team();
	//method
	void calculate()
	{
		for (size_t i = 0; i < list_submit.size(); i++)
		{
			bool find = false;
			for (size_t j = 0; j < list_submit.size(); j++)
			{
				if (list_submit[j].type==true && list_submit[j].qu==list_submit[i].qu)
				{
					find = true;
					break;
				}
			}
			if (find)
			{
				if (list_submit[i].type==true)
				{
					penalti += list_submit[i].time;
					number_of_ac++;
				}
				else
				{
					penalti += 20;
				}
			}
		}
	}
	//
	int team_name;
	int penalti;
	int number_of_ac;
	vector<submit>list_submit;
private:
	
};

team::team()
{
	penalti = 0;
	number_of_ac = 0;
}

team::~team()
{
}
//
vector<team>list_of_teams;
void input(string str)
{
	int new_team_name=0;
	char type;
	int nqu=0, ntime=0;
	int index=0;
	type = str[str.length() - 1];
	while (str[index] != ' ')
	{
		new_team_name *= 10;
		new_team_name += str[index]-'0';
		index++;
	}
	bool z = false;
	if (type=='C' || type=='I')
	{
		z = true;
		while (str[index]==' ')
		{
			index++;
		}
		while (str[index] != ' ')
		{
			nqu *= 10;
			nqu += str[index] - '0';
			index++;
		}
		while (str[index] == ' ')
		{
			index++;
		}
		while (str[index] != ' ')
		{
			ntime *= 10;
			ntime += str[index] - '0';
			index++;
		}
		bool find = false;
		for (size_t i = 0; i < list_of_teams.size(); i++)
		{
			if (list_of_teams[i].team_name==new_team_name)
			{
				find = true;
				bool find_qu = true;
				for (size_t j = 0; j < list_of_teams[i].list_submit.size(); j++)
				{
					if (list_of_teams[i].list_submit[j].qu==nqu && list_of_teams[i].list_submit[j].type==true)
					{
						find_qu = false;
						break;
					}
				}
				if (find_qu)
				{
					if (type == 'C')
					{
						list_of_teams[i].list_submit.push_back(submit(true, ntime, nqu));
					}
					else
					{
						list_of_teams[i].list_submit.push_back(submit(false, ntime, nqu));
					}
				}
				break;
			}
		}
		if (!find)
		{
			list_of_teams.push_back(team());
			list_of_teams[list_of_teams.size() - 1].team_name = new_team_name;
			if (type == 'C')
			{
				list_of_teams[list_of_teams.size() - 1].list_submit.push_back(submit(true, ntime, nqu));
			}
			else
			{
				list_of_teams[list_of_teams.size() - 1].list_submit.push_back(submit(false, ntime, nqu));
			}
		}
	}
	else
	{
		bool find = false;
		for (size_t i = 0; i < list_of_teams.size(); i++)
		{
			if (list_of_teams[i].team_name == new_team_name)
			{
				find = true;
				break;
			}
		}
		if (!find)
		{
			list_of_teams.push_back(team());
			list_of_teams[list_of_teams.size() - 1].team_name = new_team_name;
		}
	}
	return;
}
//
bool ui(int a, int b)
{
	if (list_of_teams[a].number_of_ac > list_of_teams[b].number_of_ac)
	{
		return true;
	}
	else if (list_of_teams[a].number_of_ac < list_of_teams[b].number_of_ac)
	{
		return false;
	}
	else
	{
		if (list_of_teams[a].penalti < list_of_teams[b].penalti)
		{
			return true;
		}
		else if (list_of_teams[a].penalti > list_of_teams[b].penalti)
		{
			return false;
		}
		else
		{
			if (list_of_teams[a].team_name< list_of_teams[b].team_name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	return false;
}
//
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--)
	{
		list_of_teams.clear();
		string sub;
		while (getline(cin,sub) && sub!="")
		{
			input(sub);
		}
		//processing
		for (size_t i = 0; i < list_of_teams.size(); i++)
		{
			list_of_teams[i].calculate();
		}
		//sort
		for (size_t i = 0; i < list_of_teams.size(); i++)
		{
			for (size_t j = 0; j < list_of_teams.size()-1-i; j++)
			{
				if (ui(j,j+1))
				{
					swap(list_of_teams[j], list_of_teams[j + 1]);
				}
			}
		}
		//output
		for (int i = list_of_teams.size()-1; i >= 0; i--)
		{
			cout << list_of_teams[i].team_name << " " << list_of_teams[i].number_of_ac << " " << list_of_teams[i].penalti << endl;
		}
		if (tc)
		{
			cout << endl;
		}
	}
}
