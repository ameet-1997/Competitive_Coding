#include<stdio.h>

int main()
{
	int test,*a;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		int n;
		scanf("%d",&n);
		a=new int[n];
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[j]);
		}
		
	}
}
