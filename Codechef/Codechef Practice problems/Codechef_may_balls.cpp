#include<stdio.h>

int main()
{	int answer;
	for(int i=1;i<=4;++i)
	{
		printf("1\n");
		printf("1 %d\n",i);
		printf("1 %d\n",i+1);
		scanf("%d",&answer);
		if(answer==-1)
		{
			printf("2\n%d",i+1);
			break;
		}
		else if(answer==1)
		{
			printf("2\n%d",i);
			break;
		}
		fflush(stdout);
		
		
	}
	
}
