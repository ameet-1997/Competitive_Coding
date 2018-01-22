#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
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

//vector< set<int> > field(3);

map< int,pair<int,pair<int,int> > > obstacles;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		obstacles.erase(obstacles.begin(),obstacles.end());
		int n,q;

		int x,y;
		for(int i=0;i<q;++i)
		{
			cin>>x>>y;
			auto it = obstacles.find(x);

			if(it != obstacles.end())
			{
				if(y == 1)
				{
					it->second.first = 1;
				}
				else if(y == 2)
				{
					it->second.second.first = 1;	
				}
				else
				{
					it->second.second.second = 1;
				}
			}
			else
			{
				if(y == 1)
				{
					obstacles[x] = mp(1,mp(0,0));
				}
				else if(y == 2)
				{
					obstacles[x] = mp(0,mp(1,0));
				}
				else
				{
					obstacles[x] = mp(0,mp(0,1));
				}				
			}
		}


		auto it = obstacles.begin();

		vector<int> status(3);	// All three columns can be used for visiting the rows
		status[0] = 1;
		status[1] = 1;
		status[2] = 1;

		int answer = -1;

		while(it != --obstacles.end())
		{
			if( (status[0] == 1 && it->second.first == 0) || (status[1] == 1 && it->second.second.first == 0) || (status[2] == 1 && it->second.second.second == 0) )
			{	
				int temp1,temp2,temp0;

				temp0 = status[0];
				temp1 = status[1];
				temp2 = status[2];

				status[0] = 0;
				status[1] = 0;
				status[2] = 0;

				int check = it->first;
				it++;

				if( it->first > check + 1)
				{
					status[0] = 1;
					status[1] = 1;
					status[2] = 1;
					it--;
				}
				else
				{	
					it--;
					if(temp0 == 1 && it->second.first == 0)
					{
						status[0] = 1;
						status[1] = 1;
					}

					if(status[1] == 1 && it->second.second.first == 0)
					{
						status[0] = 1;
						status[1] = 1;
						status[2] = 1;
					}

					if(status[2] == 1 && it->second.second.second == 0)
					{
						status[2] = 1;
						status[1] = 1;
					}
				}
			}
			else
			{
				answer = it->first-1;
				break;
			}

			it++;
		}

		if(answer == -1)
		{
			cout<<n<<"\n";
		}
		else
		{
			cout<<answer<<"\n";
		}
	}
}

/*int main()
{
	int test;
	cin>>test;

	while(test--)
	{	
		field[0].erase(field[0].begin(),field[0].end());
		field[1].erase(field[1].begin(),field[1].end());
		field[2].erase(field[2].begin(),field[2].end());

		int n,q;
		cin>>n>>q;

		int temp1,temp2;
		for(int i=0;i<q;++i)
		{
			cin>>temp1>>temp2;
			field[temp2-1].insert(temp1);
		}

		auto it = field[0].begin();

		int answer = -1;

		while(it != field[0].end())
		{
			if( (field[1].find(*it)!=field[1].end()) && field[2].find(*it)!=field[2].end() )
			{
				answer = *it;
			}
			it++;
		}

		if(answer == -1)
		{
			cout<<n<<"\n";
		}
		else
		{
			cout<<answer-1<<"\n";
		}

	}
}*/ 
