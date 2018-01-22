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
	int test;
	cin>>test;

	string s;

	vi number_of_ones(100000);
	vi number_of_stops(100000);

	while(test--)
	{
		cin>>s;
		fill(number_of_ones.begin(), number_of_ones.end(),0);
		fill(number_of_stops.begin(), number_of_stops.end(),0);
		ll total_without_stopping = 0;

		int len = s.length();
		for(int i=len-2;i>=0;--i)
		{
			if(s[i+1] == '1')
			{
				number_of_ones[i] = number_of_ones[i+1]+1;
			}
			else
			{
				number_of_ones[i] = number_of_ones[i+1];	
			}
		}

		if(s[len-1] == '0')
		{
			number_of_stops[len-1] = 1;
		}

		for(int i=len-2;i>=0;--i)
		{
			if(s[i] == '1')
			{
				number_of_stops[i] = number_of_stops[i+1];
			}
			else if(s[i] == '0')
			{
				if(s[i+1] == '1')
				{
					number_of_stops[i] = number_of_stops[i+1] + 1;
				}
				else
				{
					number_of_stops[i] = number_of_stops[i+1];
				}
			}
		}

		for(int i=0;i<len-1;++i)
		{	
			if(s[i] == '1')
			{
				total_without_stopping += ((len-1)-i)-number_of_ones[i];	
			}
			
		}

		ll total_including_stopping = 0;

		for(int i=0;i<len-1;++i)
		{
			if(s[i] == '1')
			{
				total_including_stopping += number_of_stops[i];
			}
		}

		cout<<total_without_stopping+total_including_stopping<<"\n";

	}
} 
