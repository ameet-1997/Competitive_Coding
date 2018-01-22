#include<stdio.h>
int main()
{
	int test,index1,index2,status=1,count=0;
	long int a,b,power[24],product=1;
	for(int i=0;i<24;++i)
	{
		power[i]=product;
		product=product*2;
	}
	
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld%ld",&a,&b);
		for(int j=0;j<24;++j)
		{
			if(b==power[j])
			{
				index1=j;
				break;
			}
		}
		
		while(1)
		{
			for(int j=0;power[j]<=a;++j)
			{
				if(a==power[j])
				{	index2=j;
					status=0;
					break;
				}
			}
			if(status==0)
			{
				break;
			}
			else
			{
			
				a=a/2;
				count++;	
			}
		}
		
		if(index1>=index2)
		{
			printf("%d\n",count+index1-index2);
		}
		else
		{
			printf("%d\n",count+index2-index1);
		}
		count=0;
		status=1;		
	}
}
