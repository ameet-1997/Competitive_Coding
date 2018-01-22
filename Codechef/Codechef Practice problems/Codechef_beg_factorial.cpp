#include<stdio.h>

int main()
{
	long int test,n,count=0,div=5;
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		while(div<=n)
		{
			count=count+n/div;
			div=div*5;
		}
		printf("%ld\n",count);
		div=5;
		count=0;
	}
}
