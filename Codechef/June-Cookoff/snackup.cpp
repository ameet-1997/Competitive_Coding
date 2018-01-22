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

vector<int> primes(101);

int main()
{	
	void sieve();
	int test;
	cin>>test;

	sieve();

	// for(int i=0;i<=100;++i)
	// {
	// 	cout<<primes[i]<<" ";
	// }
	// cout<<"\n";

	while(test--)
	{
		int n;
		cin>>n;

		int per;
		if(primes[n] == 0)
		{
			per = n;
		}
		else
		{
			per = primes[n];
		}

		cout<<n*n/per<<"\n";	// Number of rounds

		vector<int> numbers(per);
		rep(i,per)
		{
			numbers[i] = i+1;
		}

		for(int i=1;i<n;i+=per) 	// For recipes
		{
			for(int j=1;j<n;j+=per) 	// For numbers
			{
				for(int k=0;k<per;++k) 	// For printing the numbers
				{	
					//cout<<"Number of judges invited are : "<<per<<"\n";
					cout<<per<<"\n";
					for(int l=0;l<per;++l)
					{	
						if(l+i+1 > per+i-1)
						{
							cout<<numbers[(l+k)%per]+j-1<<" "<<(l+i)<<" "<<i<<"\n";
						}
						else
						{
							cout<<numbers[(l+k)%per]+j-1<<" "<<(l+i)<<" "<<(l+i+1)<<"\n";
						}
						
					}
				}
			}
		}


	}
} 


void sieve()
{
	fill(primes.begin(), primes.end(), 0);

	for(int i=2;i<=100;++i)
	{
		if(primes[i] == 0)
		{
			int k = 2;
			while(k*i <= 100)
			{
				primes[k*i] = i;
				k++;
			}
		}
	}
}
