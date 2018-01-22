#include <bits/stdc++.h>
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

vi primes(5000001);
vl dp(5000001);

int main()
{	
	void sieve(int);
	int t,l,r;
	cin>>t>>l>>r;

	fill(primes.begin(), primes.end(), 0);
	fill(dp.begin(), dp.end(), 0);
	sieve(5000000);

	// for(int i=0;i<50;++i)
	// {
	// 	cout<<primes[i]<<" ";
	// }
	// cout<<"\n";

	dp[1] = 0;

	for(int i=2;i<=5000000;++i)
	{
		ll temp = i*(i-1)/2;

		int cur = i;

		while(primes[cur] != 0)
		{
			temp = min(temp, i*(primes[cur]-1)/2 + dp[i/primes[cur]]);
			temp = min(temp, i*(i/primes[cur]-1)/2 + dp[primes[cur]]);
			cur = cur/primes[cur];
		}

		dp[i] = temp;
	}

	ll answer = 0;
	ll powe = 1;

	for(int i=l;i<=r;++i)
	{
		answer = answer + powe*dp[i];
		answer %= mod;
		powe *= t;
	}

	cout<<answer<<"\n";
} 


void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(primes[i] == 0)
		{
			int current = 2*i;

			while(current <= n)
			{
				primes[current] = i;
				current += i;
			}
		}
	}
}