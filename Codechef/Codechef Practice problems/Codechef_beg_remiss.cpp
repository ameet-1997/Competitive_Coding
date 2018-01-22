#include<stdio.h>

int main()
{
	int test;
	long int a,b;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld",&a);
		scanf("%ld",&b);
		if(a>=b)
		{
			printf("%ld %ld",a,a+b);
		}
		else
		{
			printf("%ld %ld",b,a+b);
		}
		printf("\n");
	}
}
