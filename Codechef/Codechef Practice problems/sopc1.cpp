#include<stdio.h>
int main()
{
	long int n,product=2,exp1=0,exp2=0,exp3=0,find,count=0;
	scanf("%ld",&n);
	find=n;
	while((find/product)!=0)
	{
		exp1=exp1+(find/product);
		product=product*2;
	}
	product=2;
	for(long int j=0;j<=n;++j)
	{
		find=j;
		while((find/product)!=0)
		{
			exp2=exp2+(find/product);
			product=product*2;
		}
		product=2;
		find=n-j;
		while((find/product)!=0)
		{
			exp3=exp3+(find/product);
			product=product*2;
		}
		product=2;
		if(exp1==(exp2+exp3))
		{
			count++;
		}
		exp2=0;
		exp3=0;
		
	}
	
	printf("%ld",count);
	
}

