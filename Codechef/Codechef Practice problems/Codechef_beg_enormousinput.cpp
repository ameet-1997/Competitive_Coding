#include<stdio.h>

int main()
{
	long int n,k,temp,count=0;
	scanf("%ld%ld",&n,&k);
	for(long int i=0;i<n;++i)
	{
		scanf("%ld",&temp);
		if(temp%k==0)
		{
			count++;
		}
		
	}	
	
	printf("%ld",count);
}
