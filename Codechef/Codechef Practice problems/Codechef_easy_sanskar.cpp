#include<stdio.h>

int main()
{
	int test,n,k;
	long int a[21],sum=0,division,temp;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d%d",&n,&k);
		for(int j=0;j<n;++j)
		{
			scanf("%ld",&a[j]);
			sum=sum+a[j];
		}
		if(((float)sum)/k!=sum/k)
		{
			printf("no\n");
		}
		else
		{
			division=sum/k;
			for(int y=0;y<n;++y)
			{
				
				for(int x=0;x<n-1-y;++x)
				{
					if(a[x]>a[x+1])
					{
						temp=a[x+1];
						a[x+1]=a[x];
						a[x]=temp;
					}
				}
			}
			
			
		}
	}
}
