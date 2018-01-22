#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 

class goals{
public:
	int points;
	int goal_difference;
	int goals_scored;
	string name;

	goals()
	{
		points = 0;
		goal_difference = 0;
		goals_scored = 0;
	}

};


int main()
{	
	bool myfunc(goals,goals);
	int n;
	cin>>n;

	map<string,goals> teams;

	map<string,int> check_validity;

	rep(i,n)
	{
		string temp;
		cin>>temp;
		goals current;
		current.name = temp;

		teams[temp] = current;
	}

	int m;
	cin>>m;

	bool flag = true;

	rep(i,m)
	{
		string team1, team2;
		cin>>team1>>team2;

		if(team1 < team2)
		{
			string a = team1;
			a.append(team2);
			if(check_validity.find(a) == check_validity.end())
			{
				check_validity[a] = 1;
			}
			else
			{
				check_validity[a] += 1;
				if(check_validity[a] > 2)
				{
					flag = false;
				}
			}
		}
		else
		{
			string a = team2;
			a.append(team1);
			if(check_validity.find(a) == check_validity.end())
			{
				check_validity[a] = 1;
			}
			else
			{
				check_validity[a] += 1;
				if(check_validity[a] > 2)
				{
					flag = false;
				}
			}			
		}

		if(team1 == team2)
		{
			flag = false;
		}
		else
		{
			int score1, score2;
			cin>>score1>>score2;

			if(score1 > score2)
			{
				teams[team1].points += 2;
				teams[team1].goal_difference += (score1 - score2);
				teams[team2].goal_difference += (score2 - score1);
				teams[team1].goals_scored += score1;
				teams[team2].goals_scored += score2;
			}
			else if(score2 > score1)
			{
				teams[team2].points += 2;
				teams[team2].goal_difference += (score2 - score1);
				teams[team1].goal_difference += (score1 - score2);
				teams[team1].goals_scored += score1;
				teams[team2].goals_scored += score2;	
			}
			else
			{
				teams[team2].points += 1;
				teams[team1].points += 1;
				teams[team2].goal_difference += (score2 - score1);
				teams[team1].goal_difference += (score1 - score2);
				teams[team1].goals_scored += score1;
				teams[team2].goals_scored += score2;	
			}
		}
	}


	vector<goals> order;

	map<string,goals>::iterator it = teams.begin();

	while(it != teams.end())
	{
		order.push_back(it->second);
		it++;
	}

	sort(order.begin(), order.end(), myfunc);

	if(flag)
	{
		rep(i,n)
		{	
			cout<<order[i].name;
			if(i < n-1)
			{
				cout<<"\n";
			}
		}
	}
	else
	{
		cout<<"Invalid Input";
	}

}

bool myfunc(goals a, goals b)
{
	if(a.points > b.points)
	{
		return true;
	}
	else if(a.points < b.points)
	{
		return false;
	}
	else
	{
		if(a.goal_difference > b.goal_difference)
		{
			return true;
		}
		else if(a.goal_difference < b.goal_difference)
		{
			return false;
		}
		else
		{
			if(a.goals_scored > b.goals_scored)
			{
				return true;
			}
			else if(a.goals_scored < b.goals_scored)
			{
				return false;
			}
			else
			{
				transform((a.name).begin(), (a.name).end(), (a.name).begin(), ::tolower);
				transform((b.name).begin(), (b.name).end(), (b.name).begin(), ::tolower);

				if(a.name < b.name)
				{
					return true;
				}
				else
				{
					false;
				}
			}			
		}		
	}
}