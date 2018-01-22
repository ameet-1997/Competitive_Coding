#include<stdio.h>

int main()
{
	int test;
	long int n,m=0;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		while(n>0)
		{
			m=m*10+n%10;
			n=n/10;
		}
		printf("%ld\n",m);
		m=0;
	}
}
