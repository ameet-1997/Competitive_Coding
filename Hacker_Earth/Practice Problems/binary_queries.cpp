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

 

vi input(1000000);

int main()
{	
	std::ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}

	for(int i=0;i<q;++i)
	{
		int query;
		cin>>query;

		if(query == 1)
		{
			int index;
			cin>>index;

			if(input[index-1] == 1)
			{
				input[index-1] = 0;	
			}
			else
			{
				input[index-1] = 1;
			}
		}
		else
		{
			int l,r;
			cin>>l>>r;

			if(input[r-1] == 1)
			{
				cout<<"ODD\n";
			}
			else
			{
				cout<<"EVEN\n";
			}
		}
	}
} 
