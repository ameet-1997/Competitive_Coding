#include <stdio.h>

int main()
{	
	long long int gcd(long long int,long long int);
	long long int test;

	long long int a[41];
	a[1] = 1;

	for(long long int i=2;i<=40;++i)
	{
		if(a[i-1] > i)
		{
			a[i] = i*a[i-1]/gcd(a[i-1],i);
		}
		else
		{
			a[i] = i*a[i-1]/gcd(i,a[i-1]);
		}
	}

	scanf("%lld",&test);

	for(long long int tester = 0;tester<test;++tester)
	{
		long long int n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
} 



long long int gcd(long long int a,long long int b)
{
	if(a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}