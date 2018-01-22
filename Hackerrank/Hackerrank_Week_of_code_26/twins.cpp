#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int a[100000];
int input[1000000];


int main()
{	
	int check_prime(int);
	void construct_sieve(void);
	// Calculate primes for first 35000 numbers
	int m,n;


	cin>>m>>n;

	if(n<m)
	{
		swap(n,m);
	}


	construct_sieve();

	int cur=0;

	for(int j=1;j<=35000;++j)
	{
		if(a[j] == 0)
		{
			a[cur] = j+1;
			cur++;
		}
	}

	/*for(int j=0;j<100;++j)
	{
		cout<<a[j]<<" ";
	}
	cout<<"\n";*/

	for(int j=m;j<=n;++j)
	{
		input[j-m] = check_prime(j);
	}

	int count = 0;

	for(int i=m;i<=n-2;++i)
	{
		if((input[i-m] == 1)&&(input[i-m+2] == 1))
		{
			count++;
		}
	}

	cout<<count<<"\n";
	return 0;
}


int check_prime(int number)
{
	for(int i=0;a[i] <= sqrt(number) + 1;++i)
	{
		if(number%a[i] == 0)
		{
			return 0;
		}
	}

	if(number == 1)
	{
		return 0;
	}

	return 1;
} 


void construct_sieve(void)
{	

	for(long long int i=2;i<=35000;++i)
	{	
		if(a[i-1] == 1)
		{
			continue;	//If not prime, then no need to evaluate
		}

		long long int check = 2;
		long long int temp = check*i;

		while(temp <= 35000)
		{
			a[temp-1] = 1;	//1 means not prime
			check++;
			//temp = temp+check;
			temp = check*i;
		}
	}
}