#include<stdio.h>
#include<math.h>

int main()
{
	long int test,flag=0;
	double temp;
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		long int n;
		scanf("%ld",&n);
		for(long int j=n-1;j>=1;--j)
		{		
			temp=n*n-j*j;
			temp=sqrt(temp);
			if(ceil(temp)-floor(temp)<0.1)
			{	
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("NO\n");
		}
		else
		{
			flag=0;
		}
	}
}
