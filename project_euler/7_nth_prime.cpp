#include <stdio.h>


#define ll long long

ll a[1000001];

int main()
{
	void construct_sieve();

	construct_sieve();

	
	ll count = 0;

	for(ll i=1;i<1000001;++i)
	{
		if(a[i] == 0)
		{
			a[count] = i+1;
			count++;
		}
	}

	ll test;
	scanf("%lld",&test);

	for(ll i=0;i<test;++i)
	{
		ll n;
		scanf("%lld",&n);
		
		printf("%lld\n",a[n-1]);
	}

}




void construct_sieve()
{	

	for(long long int i=2;i<=1000000;++i)
	{	
		if(a[i-1] == 1)
		{
			continue;	//If not prime, then no need to evaluate
		}

		long long int check = 2;
		long long int temp = check*i;

		while(temp <= 1000000)
		{
			a[temp-1] = 1;	//1 means not prime
			check++;
			temp = check*i;
		}
	}
} 
