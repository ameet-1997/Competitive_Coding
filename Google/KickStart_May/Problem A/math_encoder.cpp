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

vi input(100000);

int main()
{
	long long test;
	cin>>test;

	for(long long zz=1;zz<=test;++zz)
	{
		long long n;
		cin>>n;

		for(long long i=0;i<n;++i)
		{
			cin>>input[i];
		}

		ll answer = 0;

		for(long long i=0;i<n;++i)
		{
			for(long long j=i;j<n;++j)
			{
				if(j!=i)
				{	
					answer += pow(2,j-i-1)*(input[j]-input[i]);
					answer %= mod;
				}
			}
		}

		cout<<"Case #"<<zz<<": "<<answer<<"\n";
	}
} 

/*
long long main()
{
	long long test;
	cin>>test;

	for(long long zz=1;zz<=test;++zz)
	{
		long long n;
		cin>>n;

		set<long long> duplicate;

		for(long long i=0;i<n;++i)
		{
			cin>>input[i];
			duplicate.insert(input[i]);
		}

		input.assign(duplicate.begin(),duplicate.end());
		n = duplicate.size();

		ll answer = 0;

		for(long long i=0;i<n;++i)
		{
			for(long long j=i;j<n;++j)
			{
				if(j!=i)
				{	
					answer += pow(2,j-i-1)*(input[j]-input[i]);
				}
			}
		}

		cout<<"Case #"<<zz<<": "<<answer<<"\n";
	}
}
*/


long long pow(long long x, long long n)
{
	if(x == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return x%mod;
	}
	else if(n == 0)
	{
		return 1;
	}
	else
	{
		if(n%2 == 0)
		{
			ll answer = pow(x,n/2);
			return (answer*answer)%mod;
		}
		else
		{
			ll answer = pow(x,n/2);
			return (((answer*answer)%mod)*x)%mod;
		}
	}
}


