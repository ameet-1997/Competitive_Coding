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

graph[200][200];
 
int main()
{	
	int find_distance(void);

	int test;

	cin>>test;
	while(test--)
	{
		int n,m,k1,k2;
		cin>>n>>m>>k1>>k2;

		int i,j;

		rep(i,n)
		{
			rep(j,n)
			{
				cin>>graph[i][j];
			}
		}

		int d = find_distance();

		if(d%2 == 0)
		{
			cout<<d/2<<"\n";
		}
		else
		{
			cout<<d/2+1<<"\n";
		}
	}
}


int find_distance(void)
{
	queue<pii> q;

	q.push(mp(0,0));
	q.push(mp(-1,-1));

	int dist = 0;


	while(!q.empty())
	{
		if(q.front().ff == -1)
		{
			q.pop();
			q.push(mp(-1,-1));

		}
		else if((q.front().ff == 0)&&(q.front().ss == m-1))
		{
			return dist;
		}
		else
		{
			int i=0;
			int j=0;
			f(i,q.front().ff-k,q.front().ff+k)
			{
				f(j,q.front().ss-k,q.front().ss+k)
				{
					if((i>=0)&&(i<n)&&(j>=0)&&(j<n)&&(graph[i][j] == 0))
					{
						q.push(mp(i,j));
					}
				}
			}
		}
	}

}