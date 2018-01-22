#include<stdio.h>

int main()
{
	int test,status=1;
	long int k,leaves=0,stems=0,prev=0;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld",&k);
		scanf("%ld",&leaves);
		if(leaves==1)
		{
			stems=0;
		}
		else
		{
			stems=2;
		}
		prev=leaves;
		for(long int j=1;j<=k-2;++j)
		{
			scanf("%ld",&leaves);
			if(leaves<=prev+stems)
			{
				stems=(stems-(leaves-prev))*2;
				prev=leaves;	
			}
			else
			{
				printf("No\n");
				status=0;
				break;
			}
		}
		scanf("%ld",&leaves);
		if(leaves!=stems+prev)
		{
			printf("No\n");
			status=0;	
		}
		stems=1;
		leaves=prev=0;
		if(status==1)
		{
			printf("Yes\n");
		}
		status=1;
	}
}
