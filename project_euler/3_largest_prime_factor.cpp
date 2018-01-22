#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

//We construct a sieve


int a[1000000];

int main()
{	
	void construct_sieve();

	long long int test;

	scanf("%lld",&test);

	construct_sieve();


	cout<<"The total number of primes below 3200 id : "<<count<<"\n";


	for(long long int i=0;i<test;++i)
	{
		long long int n;
		long long int max;

		scanf("%lld",&n);

		for(int i=1000000;i>=2;--i)
		{
			if(a[i-1] == 0)
			{
				if(n%i == 0)
				{
					max = i;
					break;
				}
			}
		}


		printf("%lld\n",max);	
		

		
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
			//temp = temp+check;
			temp = check*i;
		}
	}
}