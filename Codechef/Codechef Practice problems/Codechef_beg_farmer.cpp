#include<stdio.h>

int main()
{	int countmin(int,int);
	int test,m,n,answer,temp;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d%d",&n,&m);
		if(n>m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		answer=countmin(m,n);
		printf("%d\n",answer);
		
	}
}

int countmin(int m,int n)
{	int temp;
	if(n==0)
	{
		return 0;
	}
	temp=m/n;
	return (temp+countmin(n,m%n));
	
	
}
