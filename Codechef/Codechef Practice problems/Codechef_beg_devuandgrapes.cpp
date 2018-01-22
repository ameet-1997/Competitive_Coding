#include<stdio.h>

int main()
{
	int test,n;
	long int k,temp,count=0,div;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d%ld",&n,&k);
		for(int j=0;j<n;++j)
		{
			scanf("%ld",&temp);
			div=temp/k;
			if(div==0)
			{
				count=count+(k-temp);
			}
			else
			{
				if((temp-div*k)<(k*(div+1)-temp))
				{
					count=count+(temp-div*k);
				}
				else
				{
					count=count+k*(div+1)-temp;	
				}
			}
			
			
		}
		printf("%ld\n",count);
			count=0;
		
	}
}
