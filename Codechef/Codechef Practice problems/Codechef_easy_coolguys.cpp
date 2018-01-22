#include<stdio.h>

int main()
{	long int gcd(long int,long int);
	int test;
	long int n,gcdof,sum=0,l=1,denom;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		while(l*l<=n)
		{
			sum=sum+n/l-l+1;
			l++;
		}
		denom=n*(n-1)/2;
		gcdof=gcd(denom,sum);
		sum=sum/gcdof;
		denom=denom/gcdof;
		printf("%ld/%ld\n",sum,denom);
		sum=0;
		l=1;
		
	}
}

long int gcd(long int a,long int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}
