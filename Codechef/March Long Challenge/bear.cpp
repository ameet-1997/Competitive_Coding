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

vi sequence(100000);

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int n;
		cin>>n;

		set<int> check;

		rep(i,n)
		{
			cin>>sequence[i];
		}

		sort(sequence.begin(),sequence.begin()+n);

		if(sequence[0] != sequence[1]-1)
		{
			cout<<sequence[0]<<"\n";
		}
		else if(sequence[n-1] != sequence[n-2] + 1)
		{
			cout<<sequence[n-1]<<"\n";
		}
		else
		{
			rep(i,n)
			{
				if(check.find(sequence[i]) != check.end())
				{
					cout<<sequence[i]<<"\n";
				}
				else
				{
					check.insert(sequence[i]);
				}
			}
		}

	}
} 
