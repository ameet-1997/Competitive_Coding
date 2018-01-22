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
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< ll >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< ll,ll >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<ll,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< ll,vi ,greater< ll > >

//std::ios::sync_with_stdio(false); 

vector<ll> input(1000000);

int main()
{
	ll test;
	cin>>test;

	while(test--)
	{
		ll n;
		cin>>n;

		for(ll i=0;i<2*n;++i)
		{
			cin>>input[i];
		}

		sort(input.begin(),input.begin()+2*n);

		ll answer_index = 2*n-n/2-1;
		ll answer = input[answer_index];
		cout<<answer<<"\n";

		swap(input[2*(n/2)+1],input[answer_index]);


		int end = 2*n-1;
		for(int i=2*(n/2)+2;i<answer_index;i+=2)
		{
			swap(input[i],input[end]);
			end-=2;
		}
		//swap(input[2*(n/2)+1],input[answer_index]);

		

		for(ll i=0;i<2*n;++i)
		{
			cout<<input[i]<<" ";
		}
		cout<<"\n";
	}
} 
