#include<stdio.h>

int main()
{
	int test;
	char *a;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{	int n,k,x,y,br=0;
		scanf("%d%d",&n,&k);
		a=new char[n];
		
		for(int j=0;j<n;++j)
		{
			a[j]='0';
		}
		
		for(int j=0;j<k;++j)
		{
			scanf("%d%d",&x,&y);
			a[x]='(';
			a[y]=')';
		}
		
		for(int j=0;j<n;++j)
		{
			if(a[j]=='0')
			{
				if(br==0)
				{
					printf("(");
					br=1;
				}
				else
				{
					printf(")");
					br=0;
				}
			}
			else
			{
				printf("%c",a[j]);
			}
		}
		printf("\n");
		delete[] a;
		
	}
}
