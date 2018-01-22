#include<stdio.h>

int main()
{
	int test,min=30000,temp;
	long long int n,answer;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%lld",&n);
		for(long int j=0;j<n;++j)
		{
			scanf("%d",&temp);
			if(temp<min)
			{
				min=temp;
			}
		}
		answer=min*(n-1);
		printf("%lld\n",answer);
		min=30000;
	}
	
}
