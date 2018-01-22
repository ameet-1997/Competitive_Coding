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
#define f(i,a,b) for(int i=a;i<b;i++)
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

vector< vector< int > > graph(100000);
vi max_length(100000);
vi meeting_times(100000);

int main()
{
	int n;

	rep(i,n-1)
	{
		int x,y;
		cin>>x>>y;

		graph[x-1].pb(y-1);
		graph[y-1].pb(x-1);
	}

	//Graph recieved as input
	
	fill(max_length.begin(), max_length.begin() + n,0);
	fill(meeting_times.begin(), meeting_times.begin() + n,0);

}


void bfs()
{
	queue<int> q;
	meeting_times[0] = 0;

	q.push(0);
	q.push(-1);	//Sentinel

	int time = 1;

	while(1)
	{
		if(q.front() == -1)
		{
			q.push(-1);
			q.pop();
			time++;

			if(q.front() == -1)
			{
				return;
			}
		}
		else
		{
			int temp = q.front();

			auto it = graph[temp].begin();

			while(it != graph[temp].end())
			{
				q.push(*it);
				meeting_times[*it] = time;
				it++;
			}
		}
	}

}