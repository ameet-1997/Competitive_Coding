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

vi collatz(5000000,0);
vi max_till_now(5000000,0);


//Not working
int main()
{	
	int fill_collatz(int);
	int test;
	cin>>test;

	collatz[1] = 1;

	for(int i=2;i<=5000000;++i)
	{	
		if(collatz[i-1] == 0)
		{
			if(i%2 == 0)
			{
				collatz[i-1] = collatz[(i/2)-1] + 1;
			}
			else
			{
				fill_collatz(i);
			}			
		}

	}

	int number_max = 0;
	int number = 0;

	for(int i=1;i<5000000;++i)
	{
		if(collatz[i-1] > number_max)
		{
			number_max = collatz[i-1];
			number = i;
			max_till_now[i-1] = number;
		}
	}



	while(test--)
	{
		int n;
		cin>>n;

		cout<<max_till_now[n-1]<<"\n";

	}
}


int fill_collatz(int n)
{
	if(collatz[n-1] > 0)
	{
		return collatz[n-1];
	}
	else
	{
		if(n%2 == 0)
		{
			collatz[n-1] = fill_collatz(n/2) + 1;
			return collatz[n-1];
		}
		else
		{
			collatz[n-1] = fill_collatz(3*n+1) + 1;
			return collatz[n-1];
		}
	}
}