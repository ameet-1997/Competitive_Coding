#include <stdio.h>

int main()
{
	long long int test;

	scanf("%lld",&test);

	for(long long int i=0;i<test;++i)
	{	
		long long int n;
		scanf("%lld",&n);
		long long int answer = n*(n+1)*(3*n*n-n-2)/12;
		printf("%lld\n",answer );
	}
} 
