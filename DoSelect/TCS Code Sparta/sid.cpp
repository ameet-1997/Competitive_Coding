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

	vector<int> state(26);

	vector< vector<int> > to_be_updated(26);

	cin>>switches;

	auto it = switches.begin();

	while(it != switches.end())
	{
		to_be_updated[*it-'a'].push_back(it-switches.begin());
		it++;
	}

	fill(state.begin(), state.end(),0);

	for(int i=0;i<q;++i)
	{
		int type;
		cin>>type;

		if(type == 1)
		{	
			char c;
			cin>>c;

			state[c-'a'] = 1- state[c-'a'];
		}
		else
		{
			int l,r;
			string s;

			cin>>l>>r;
			cin>>s;

			l--;
			r--;

			int count = 0;

			for(int i=0;i<26;++i)
			{	
				if(state[i] == 0)
				{
					continue;
				}

				auto it1 = lower_bound(to_be_updated[i].begin(),to_be_updated[i].end(),l);
				auto it2 = upper_bound(to_be_updated[i].begin(),to_be_updated[i].end(),r);

				if(it1 == to_be_updated[i].end())
				{
					continue;
				}
				else if(it2 == to_be_updated[i].begin())
				{
					continue;
				}
				else
				{
					int lower_index = it1 - to_be_updated[i].begin();
					int upper_index = it2 - to_be_updated[i].begin();

					count += upper_index-lower_index;
					//cout<<(upper_index- lower_index)<<"\n";
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
