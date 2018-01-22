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
#define LIM 1000001

//std::ios::sync_with_stdio(false); 

vi primes(LIM);
vi prime_sum(LIM);
vi query(LIM);

int main()
{
	void sieve(int);
	fill(primes.begin(), primes.end(), 0);
	fill(prime_sum.begin(), prime_sum.end(), 0);
	fill(query.begin(), query.end(), 0);

	sieve(LIM);
	primes[0] = primes[1] = 1;

	int counter = 0;

	int test;
	cin>>test;

	rep(i,LIM)
	{
		if(primes[i] == 0)
		{
			counter++;
			prime_sum[i] = counter;
		}
		else
		{
			prime_sum[i] = counter;
		}
	}

	// // Check output
	// rep(i,20)
	// {
	// 	cout<<prime_sum[i]<<" ";
	// }
	// cout<<endl;

	rep(i,LIM)
	{
		if(primes[prime_sum[i]] == 0)
		{
			prime_sum[i] = 1;
		}
		else
		{
			prime_sum[i] = 0;
		}
	}

	f(i,1,LIM)
	{
		query[i] = query[i-1] + prime_sum[i];
	}

	while(test--)
	{
		int l,r;
		cin>>l>>r;

		cout<<query[r] - query[l] + prime_sum[l]<<endl;
	}


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
