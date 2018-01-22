#include<stdio.h>

int main()
{
	long int *a,n,x,count=0,cost=0;
	scanf("%ld",&n);
	a=new long int[n];
	for(long int i=0;i<n;++i)
	{
		scanf("%ld",&a[i]);
		if(a[i]<0)
		{
			count++;
		}
	}
	scanf("%ld",&x);
		while(count>=x)
		{
			for(int j=0;j<n;++j)
			{
				a[j]++;
				if(a[j]>=0)
				{
					count--;
				}
			}
			cost=cost+x;
		}
		for(int m=0;m<n;m++)
		{
			if(a[m]<0)
			{
				cost=cost-a[m];
			}
		}
	printf("%ld",cost);
	delete[] a;
}
