#include <bits/stdc++.h>
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
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

vector<ll> primes(1000000);
vector<ll> adj_prime(1000000);
vector<ll> prime_sum(1000000);

int main()
{
	void sieve(ll n);

	sieve(1000000);

	ll prime_count = 0;

	f(i,2,1000000)
	{
		if(primes[i] == 0)
		{
			adj_prime[prime_count] = i;
			prime_count++;
		}
	}

	// rep(i,20)
	// {
	// 	cout<<adj_prime[i]<<" ";
	// }
	// cout<<"\n";


	ll total = 0;
	ll count = 0;


	for(ll i=0;i<prime_count;++i)
	{	
		if(total > 12000000000)
		{
			break;
		}
		total += adj_prime[i];

		bool flag = true;

		ll till = sqrt(total)+1;

		// cout<<till<<"\n";
		for(ll j=0;(j < prime_count)&&(adj_prime[j]<=till);++j)
		{
			if(total % adj_prime[j] == 0)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
			prime_sum[count] = total;
			count++;				
		}
	}

	// rep(i,20)
	// {
	// 	cout<<prime_sum[i]<<" ";
	// }
	// cout<<"\n";

	ll n;
	cin>>n;

	ll answer;

	ll index = lower_bound(prime_sum.begin(), prime_sum.begin()+count, n) - prime_sum.begin();
	
	if(prime_sum[index] == n)
	{
		answer = index+1;
	}
	else
	{
		answer = index;
	}

	cout<<answer;
	
	// rep(i,count)
	// {
	// 	cout<<prime_sum[i]<<" ";
	// }
	// cout<<"\n";

	return 0;

}

void sieve(ll n)
{
	for(ll i=2;i<n;++i)
	{
		if(primes[i] == 0)
		{
			ll cur = i*2;
			while(cur < n)
			{
				primes[cur] = i;
				cur += i;
			}
		}
	}
}

// f(i,2,1000000)
// {
// 	if(primes[i] == 0)
// 	{	
// 		prime_count++;
// 		total += i;
// 		if(prime_count%2 == 0)
// 		{
// 			prime_sum[count] = total;
// 			count++;				
// 		}

// 	}
// }