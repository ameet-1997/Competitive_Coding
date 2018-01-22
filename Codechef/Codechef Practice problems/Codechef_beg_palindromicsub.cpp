#include<stdio.h>

int main()
{
	int test,flag=0;
	char a[1001],b[1001];
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%s",a);
		scanf("%s",b);
		for(int i=0;a[i]!='\0';++i)
		{
			for(int j=0;b[j]!='\0';++j)
			{
				if(a[i]==b[j])
				{
					printf("Yes\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag==0)
		{
			printf("No\n");
		}
		else
		{
			flag=0;
		}
	}
}
