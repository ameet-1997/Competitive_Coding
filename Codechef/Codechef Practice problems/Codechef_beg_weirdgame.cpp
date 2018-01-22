#include<stdio.h>

int main()
{
	
	int test,n,m;
	scanf("%d",&test);
	
	for(int i=0;i<test;++i)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",(n-1)*m+(m-1)*n);
	}
}
