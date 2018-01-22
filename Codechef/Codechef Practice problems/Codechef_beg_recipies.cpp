#include<stdio.h>

int main()
{	int hcf(int,int);
	int test,n,*a,gcd;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&n);
		a=new int[n];
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[j]);
		}
		if(n==1)
		{
			gcd=n;
		}
		else
		{
			gcd=hcf(a[0],a[1]);
		}
		for(int j=2;j<n;++j)
		{
			gcd=hcf(a[j],gcd);
		}
		for(int j=0;j<n;++j)
		{
			printf("%d ",a[j]/gcd);
		}
		printf("\n");
		delete[] a;
	}
}

int hcf(int a,int b)
{	int temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(b==0)
	{
		return a;
	}
	return hcf(b,a%b);		
}
