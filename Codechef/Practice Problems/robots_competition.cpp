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
//setfill - cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
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
#define tri pair< int,pii >
#define vii vector< pii >
#define vll vector< pll >
#define viii vector< tri >
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
//std::ios::sync_with_stdio(false);

int n,m,k1,k2;

int marker_value[200][200];
int visited[200][200];

int graph[200][200];
 
int main()
{	
	void find_distance(int);

	int test;

	cin>>test;
	while(test--)
	{
		int n,m,k1,k2;
		cin>>n>>m>>k1>>k2;

		int i,j;

		rep(i,n)
		{
			rep(j,m)
			{
				cin>>graph[i][j];
				marker_value[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		cout<<"here\n";

		find_distance(k1);
		find_distance(k2);
		int ans = INT_MAX;

		rep(i,n)
		{
			rep(j,m)
			{
				ans = min(ans,marker_value[i][j]);
			}
		}

		cout<<ans<<"\n";
	}
}


void find_distance(int k)
{
	queue<pii> q;

	q.push(mp(0,0));
	q.push(mp(-1,-1));

	cout<<q.

	int dist = 0;


	while(!q.empty())
	{
		if(q.front().ff == -1)
		{
			q.pop();
			q.push(mp(-1,-1));
			dist++;
			if(q.front().ff == -1)
			{
				return;
			}
		}
		else
		{
			int i=0;
			int j=0;
			f(i,q.front().ff-k,q.front().ff+k+1)
			{
				f(j,q.front().ss-k,q.front().ss+k+1)
				{
					if((i>=0)&&(i<n)&&(j>=0)&&(j<m)&&(graph[i][j] == 0)&&(visited[i][j] == 0))
					{
						q.push(mp(i,j));
						visited[i][j] = 1;
					}
				}
			}

			if(dist > (marker_value[q.front().ff][q.front().ss] = dist))
			{
				marker_value[q.front().ff][q.front().ss] = dist;
			}
			q.pop();
		}
	}

} 
