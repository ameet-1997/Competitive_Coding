#include<stdio.h>

int main()
{
	long int test,m,n;
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%ld%ld",&m,&n);
		if(m%2)
		{
			if(n%2)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
		else
		{
			printf("Yes\n");
		}
	}
}
