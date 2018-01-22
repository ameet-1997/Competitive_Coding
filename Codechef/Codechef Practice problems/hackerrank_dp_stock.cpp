#include<stdio.h>

void main()
{
	int test,n,*max,*a,current,*next;
	scanf("%d",&test);
	
	for(int i=0;i<test;++i)
	{
		scanf("%d",&n);
		a=new int[n];
		next=new int[n];
		for(int as=0;as<n;++as)
		{
			scanf("%d",&a[as]);
		}
		max=new int[n];
		current=a[n-1];
		next[n-1]=n-1;
		for(int j=n;j>=0;--j)
		{
			if(a[j]>current)
			{	next[j]
				current=a[j];
				max[j]=current
			}
			else
			{
				max[j]=current;
			}
		}
	}
}
