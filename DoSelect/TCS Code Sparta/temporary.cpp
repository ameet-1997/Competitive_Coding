/*

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

//std::ios::sync_with_stdio(false); 

int main()
{
	int n,q;

	cin>>n>>q;

	string switches;

	vector<int> state;

	cin>>switches;

	state.resize(switches.length());
	fill(state.begin(), state.end(),0);

	for(int i=0;i<q;++i)
	{
		int type;
		cin>>type;

		if(type == 1)
		{	
			char c;
			cin>>c;

			auto it = switches.begin();

			while(it != switches.end())
			{
				if(*it == c)
				{
					state[it-switches.begin()] = 1 - state[it-switches.begin()];
				}
				it++;
			}
		}
		else
		{
			int l,r;
			string s;

			cin>>l>>r;
			l--;
			r--;
			cin>>s;

			int count = 0;

			for(int i=l;i<=r;++i)
			{
				if(state[i] == 1)
				{
					count++;
				}
			}

			if(s[1] == 'n')
			{
				cout<<count<<"\n";
			}
			else
			{
				cout<<(r-l+1-count)<<"\n";
			}
		}
	}
} 
*/ 
