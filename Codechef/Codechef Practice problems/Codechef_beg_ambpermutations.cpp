#include<stdio.h>

int main()
{
	long int a[100001],n;
	int status=1;
	scanf("%ld",&n);
	while(n!=0)
	{
		for(long int i=1;i<=n;++i)
		{
			scanf("%ld",&a[i]);
		}
		for(int i=1;i<n;++i)
		{
			if(a[a[i]]!=i)
			{
				status=0;
				break;
			}
		}
		if(status==1)
		{
			printf("ambiguous\n");
		}
		else
		{
			printf("not ambiguous\n");
		}
		status=1;
		scanf("%ld",&n);
	}
	
}
