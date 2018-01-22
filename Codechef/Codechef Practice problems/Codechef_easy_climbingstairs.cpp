#include<stdio.h>

int step[10000001];

int main()
{	
	int guess,count=0;
	long int n,test,answer;
	scanf("%ld",&test);
	step[1]=1;
	step[2]=2;
	for(long int i=3;i<=10000000;++i)
	{
		step[i]=step[i-1]%1000000007+step[i-2]%1000000007;
	}
	for(long int i=0;i<test;++i)
	{
		scanf("%ld%d",&n,&guess);
		answer=step[n];
		while(answer!=0)
		{
        	if(answer%2==1)
        	{
        		count++;
			}
        	answer=answer/2;
    	}
    	if(count==guess)
    	{
    		printf("CORRECT\n");
		}
		else
		{
			printf("INCORRECT\n");
		}
		for(int z=0;z<=n;++z)
		{
			step[z]=0;
		}
		count=0;
	}
}


/*Memoization
long int steps(long int a)
{
	if(a==1)
	{
		return step[1];
	}
	if(a==2)
	{
		return step[2];
	}
	if(step[a-1]==0)
	{
		step[a-1]=steps(a-1)%1000000007;
	}
	if(step[a-2]==0)
	{
		step[a-2]=steps(a-2)%1000000007;
	}
	return (step[a-1]+step[a-2])%1000000007;
}
*/
