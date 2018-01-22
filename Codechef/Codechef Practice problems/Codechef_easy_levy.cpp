#include<stdio.h>

int main()
{	
	int a[10001];
	int multiply=0,divisor=2,n;
	long int test=0,count=0;
	
	for(int i=2;i<10001;++i)
	{
		a[i]=1;
	}
	a[0]=0;
	a[1]=0;
	while(divisor<=101)
	{	
		multiply=divisor*2;
		for(int i2=2;multiply<10001;++i2)
		{	
			a[multiply]=0;
			multiply=divisor*i2;
		}
		multiply=0;
		for(int i3=divisor+1;;i3++)
		{
			if(a[i3]==1)
			{
				divisor=i3;
				break;
			}
		}
		
	}
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			if(a[n/2-1]==1)
			{
				count++;
			}
		}
		else
		{
			for(int j=3;j<=n;++j)
			{
				if(a[j]&&a[(n-j)/2])
				{
					count++;
				}
			}
		}
		printf("%ld\n",count);
		count=0;
	}
	
}
