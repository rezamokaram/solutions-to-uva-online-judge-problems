#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
//
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
//
bool ui(string a, string b)
{
	if (a.length() == 3 && b.length() == 3)
	{
		if (a[0] == 'A' && a[1] != 'B')
		{
			if (b[0] == 'A' && b[1]!='B')
			{
				if (a[2] == '+' && b[2] == '-')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}

		}
		else if (a[0] == 'B' && a[1] != 'A')
		{
			if (b[0] == 'A' && b[1] != 'B')
			{
				return false;

			}
			else if (b[0] == 'B')
			{
				if (a[2] == '+' && b[2] == '-')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}
		else if (a[0] == 'A' && a[1] == 'B')
		{
			if (b[0] == 'A' && b[1] != 'B')
			{
				return false;
			}
			else if (b[0] == 'B')
			{
				return false;
			}
			else if (b[0] == 'A' && b[1] == 'B')
			{
				if (a[2] == '+' && b[2] == '-')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (b[0]=='A' || b[0]=='B')
			{
				return false;
			}
			if (a[2] == '+' && b[2] == '-')
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}
//
bool is_equal(string a, string b)
{
	if (a==b)
	{
		return true;
	}
	if (a[0]=='B' && a[1]=='O' || a[0] == 'O' && a[1] == 'B' || a[0] == 'B' && a[1] == 'B')
	{
		if (b[0] == 'B' && b[1] == 'O' || b[0] == 'O' && b[1] == 'B' || b[0] == 'B' && b[1] == 'B')
		{
			if (a[2]==b[2])
			{
				return true;
			}
		}
	}
	if (a[0] == 'A' && a[1] == 'O' || a[0] == 'O' && a[1] == 'A' || a[0] == 'A' && a[1] == 'A')
	{
		if (b[0] == 'A' && b[1] == 'A' || b[0] == 'A' && b[1] == 'O' || b[0] == 'O' && b[1] == 'A')
		{
			if (a[2] == b[2])
			{
				return true;
			}
		}
	}
	if (a[0] == 'B' && a[1] == 'A' || a[0] == 'A' && a[1] == 'B')
	{
		if (b[0] == 'B' && b[1] == 'A' || b[0] == 'A' && b[1] == 'B')
		{
			if (a[2] == b[2])
			{
				return true;
			}
		}
	}
	if (a[0]=='O' && a[1]=='O')
	{
		if (b[0]=='O' && b[1]=='O')
		{
			if (a[2]==b[2])
			{
				return true;
			}
		}
	}
	return false;
}
//
string sort_blood(string bl)
{
	string re=bl;
	if (re[0]=='O')
	{
		if (re[1]=='A' || re[1]=='B')
		{
			swap(re[0], re[1]);
		}
	}
	else if (re[0]=='B' && re[1]=='A')
	{
		swap(re[0], re[1]);
	}
	return re;
}
//
void blood_out(string bl)
{
	if (bl[0]==bl[1] || bl[1]=='O')
	{
		cout << bl[0]<<bl[2];
	}
	else
	{
		cout << bl;
	}
	return;
}
//
char sinret(string& p)
{
	char sine = p[p.length() - 1];
	string temp;
	for (size_t i = 0; i < p.length()-1; i++)
	{
		temp += p[i];
	}
	p = temp;
	return sine;
}
int main()
{
	int tc = 0;
	string p1, p2, c;
	string out1, out2, out3;
	int place;
	while (cin >> p1 >> p2 >> c)
	{
		if (p1=="E")
		{
			break;
		}
		out1 = p1;
		out2 = p2;
		out3 = c;
		if (p1=="?")
		{
			swap(p1, p2);
			place = 0;
		}
		else if(p2=="?")
		{
			place = 1;
		}
		else
		{
			place = 2;
		}
		vector<string>blood;
		bool fposible = true;
		//lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
		if (place==2)
		{
			//making parents blood
			if (p1.length()==2)
			{
				char sine = p1[1];
				p1[1] = 'O';
				p1 += sine;
			}
			if (p2.length() == 2)
			{
				char sine = p2[1];
				p2[1] = 'O';
				p2 += sine;
			}
			//end of make
			bool ftwo = true;
			if (p1[2]=='-' && p2[2]=='-')
			{
				ftwo = false;
			}
			//
			for (size_t i = 0; i < p1.length() - 1; i++)
			{
				for (size_t j = 0; j < p2.length() - 1; j++)
				{
					string temp;
					temp += p1[i];
					temp += p2[j];
					temp += '-';
					blood.push_back(temp);
					if (ftwo)
					{
						temp[2] = '+';
						blood.push_back(temp);
					}
				}
			}
		}
		else
		{
			//making paretns
			if (p1.length() == 2)
			{
				char sine = p1[1];
				p1[1] = 'O';
				p1 += sine;
			}
			if (c.length() == 2)
			{
				char sine = c[1];
				c[1] = 'O';
				c += sine;
			}
			//make mosh
			string mosh;
			for (size_t i = 0; i < c.length() - 1; i++)
			{
				for (size_t j = 0; j < p1.length() - 1; j++)
				{
					if (c[i]==p1[j])
					{
						mosh += c[i];
						break;
					}
				}
			}
			//
			if (mosh.length()==0)
			{
				fposible = false;
			}
			else if (mosh.length()==2)
			{
				if (p1[2]=='-' && c[2]=='+')
				{
					if (p1 == "AB-" || p1 == "AB+" || c == "AB-" || c == "AB+")
					{
						blood.push_back("AO+");
						blood.push_back("BO+");
						blood.push_back("AB+");
					}
					else if (p1 == "OO-" || p1 == "OO+" || c == "OO-" || c == "OO+")
					{
						blood.push_back("OO+");
						blood.push_back("AO+");
						blood.push_back("BO+");
					}
					else
					{
						blood.push_back("OO+");
						blood.push_back("AO+");
						blood.push_back("BO+");
						blood.push_back("AB+");
					}
				}
				else
				{
					if (p1 == "AB-" || p1 == "AB+" || c == "AB-" || c == "AB+")
					{
						blood.push_back("AO-");
						blood.push_back("AO+");
						blood.push_back("BO-");
						blood.push_back("BO+");
						blood.push_back("AB-");
						blood.push_back("AB+");
					}
					else if (p1 == "OO-" || p1 == "OO+" || c == "OO-" || c == "OO+")
					{
						blood.push_back("OO-");
						blood.push_back("OO+");
						blood.push_back("AO-");
						blood.push_back("AO+");
						blood.push_back("BO-");
						blood.push_back("BO+");
					}
					else
					{
						blood.push_back("OO-");
						blood.push_back("OO+");
						blood.push_back("AO-");
						blood.push_back("AO+");
						blood.push_back("BO-");
						blood.push_back("BO+");
						blood.push_back("AB-");
						blood.push_back("AB+");
					}
				}
				
			}
			else
			{
				//def
				string def;
				if (c[0]==mosh[0])
				{
					def += c[1];
				}
				else
				{
					def += c[0];
				}
				//
				for (size_t i = 0; i < c.length()-1; i++)
				{
					if (c[i]==mosh[0])
					{
						continue;
					}
					bool ftt = true;
					if (c[2]=='+' && p1[2]=='-')
					{
						ftt = false;
					}
					string nt;
					nt += c[i];
					nt += 'A';
					nt += '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
					//
					nt[1] = 'B';
					nt[2] = '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
					//
					nt[1] = 'O';
					nt[2] = '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
				}
				for (size_t i = 0; i < p1.length() - 1; i++)
				{
					if (p1[i] == mosh[0])
					{
						continue;
					}
					else if (def[0]=='A' || def[0]=='B')
					{
						continue;
					}
					bool ftt = true;
					if (c[2] == '+' && p1[2] == '-')
					{
						ftt = false;
					}
					string nt;
					nt += p1[i];
					nt += 'A';
					nt += '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
					//
					nt[1] = 'B';
					nt[2] = '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
					//
					nt[1] = 'O';
					nt[2] = '+';
					blood.push_back(nt);
					if (ftt)
					{
						nt[2] = '-';
						blood.push_back(nt);
					}
				}
			}
		}
        //iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
		//cheking output
		vector<int>check;
		for (size_t i = 0; i < blood.size(); i++)
		{
			blood[i] = sort_blood(blood[i]);
			check.push_back(1);
		}
		for (int i = blood.size() - 1; i >= 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (is_equal(blood[i],blood[j]))
				{
					check[i]=0;
					break;
				}
			}
		}
		vector<string>list;
		for (size_t i = 0; i < blood.size(); i++)
		{
			if (check[i]==1)
			{
				list.push_back(blood[i]);
			}
		}
		blood.clear();
		//sort(list.begin(), list.end(),ui);
		for (size_t i = 0; i < list.size(); i++)
		{
			for (size_t j = 0; j < list.size() - 1 - i; j++)
			{
				if (ui(list[j],list[j+1]))
				{
					swap(list[j], list[j + 1]);
				}
			}
		}
		//end chek
		//output zone
		tc++;
		cout << "Case " << tc << ": ";
		if (!fposible)
		{
			if (place == 0)
			{
				cout << "IMPOSSIBLE ";
				cout << out2 << " ";
				cout << out3;

			}
			else if (place == 1)
			{
				cout << out1 << " ";
				cout << "IMPOSSIBLE ";
				cout << out3;
			}
			else
			{
				cout << out1 << " ";
				cout << out2 << " ";
				cout << "IMPOSSIBLE";
			}
		}
		else
		{
			if (place == 0)
			{
				//loop for bloods
				if (list.size() > 1)
				{
					cout << "{";
					for (size_t i = 0; i < list.size(); i++)
					{
						if (i != 0)
						{
							cout << " ";
						}
						blood_out(list[i]);
						if (i != list.size() - 1)
						{
							cout << ",";
						}
					}
					cout << "}";
				}
				else
				{
					blood_out(list[0]);
				}
				//end loop
				cout << " " << out2 << " " << out3;
			}
			else if (place == 1)
			{
				cout << out1;
				//loop for bloods
				if (list.size() > 1)
				{
					cout << " {";
					for (size_t i = 0; i < list.size(); i++)
					{
						if (i != 0)
						{
							cout << " ";
						}
						blood_out(list[i]);
						if (i != list.size() - 1)
						{
							cout << ",";
						}
					}
					cout << "}";
				}
				else
				{
					cout << " ";
					blood_out(list[0]);
				}
				//end loop
				cout << " " << out3;
			}
			else
			{
				cout << out1 << " " << out2;
				//loop for bloods
				if (list.size() > 1)
				{
					cout << " {";
					for (size_t i = 0; i < list.size(); i++)
					{
						if (i != 0)
						{
							cout << " ";
						}
						blood_out(list[i]);
						if (i != list.size() - 1)
						{
							cout << ",";
						}
					}
					cout << "}";
				}
				else
				{
					cout << " ";
					blood_out(list[0]);
				}
				//end loop
			}
		}
		cout << endl;
		//end of output
	}
}
