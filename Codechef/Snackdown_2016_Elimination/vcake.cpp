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


int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int r,c,m,k,j;
		cin>>r>>c>>m>>k>>j;

		int total = m+k+j;

		if(total != r*c)
		{
			cout<<"No\n";
		}
		else
		{	
			int flag = 0;
			if(m%c == 0)
			{
				if((m/c < r)&&(k%(r-m/c) == 0))
				{
					
					flag = 1;
				}
			}
			if(k%c == 0)
			{
				if((k/c < r)&&(m%(r-k/c) == 0))
				{
					flag = 1;
				}
			}
			if(j%c == 0)
			{
				if((j/c < r)&&(k%(r-j/c) == 0))
				{
					flag = 1;
				}
			}
			if(m%r == 0)
			{
				if((m/r < c)&&(k%(c-m/r) == 0))
				{
					flag = 1;
				}
			}
			if(k%r == 0)
			{
				if((k/r < c)&&(m%(c-k/r) == 0))
				{
					flag = 1;
				}
			}
			if(j%r == 0)
			{
				if((j/r < c)&&(k%(c-j/r) == 0))
				{
					flag = 1;
				}
			}
			

			if(flag == 0)
			{
				cout<<"No\n";
			}
			else
			{
				cout<<"Yes\n";
			}

		}
	}
} 
