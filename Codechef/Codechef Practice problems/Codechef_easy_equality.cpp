#include<stdio.h>
long int b[100000];
int main()
{
	long int test,n,*a,max;
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		a=new long int[n];
		for(long int j=0;j<n;++j)
		{
			scanf("%d",&a[j]);
			b[a[j]]++;
		}
		max=b[0];
		b[0]=0;
		for(int k=1;k<100000;++k)
		{
			if(b[k]>max)
			{
				max=b[k];
			}
			b[k]=0;
		}
		printf("%ld\n",n-max);	
	}
}
