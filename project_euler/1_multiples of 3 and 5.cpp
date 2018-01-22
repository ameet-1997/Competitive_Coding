#include <stdio.h>

int main()
{
	long long int test;
	scanf("%lld",&test);

	for(long long int i=0;i<test;++i)
	{
		long long int n;
		scanf("%lld",&n);

		long long int three,five,fifteen;

		three = (n-1)/3;
		five = (n-1)/5;
		fifteen = (n-1)/15;

		long long int answer;

		answer = 3*(three)*(three+1)/2 + 5*(five)*(five + 1)/2 - 15*(fifteen)*(fifteen + 1)/2;

		printf("%lld\n",answer);
	}
} 
