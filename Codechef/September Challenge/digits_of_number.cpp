#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);

	char a[100002];

	for(int i=0;i<test;++i)
	{
		scanf("%s",a);

		int sum1=0,sum0=0,flag=1;

		for(int j=0;a[j]!='\0';++j)
		{
			if(((int)(a[j]))==48)
			{
				sum0++;
			}

			else
			{
				sum1++;
			}

			if((sum0>=2)&&(sum1>=2))
			{	
				flag=0;
				break;
			}

		}

		
		if((sum0==0)||(sum1==0))
		{
			flag=0;
		}

		if(a[1]=='\0')
		{
			flag=1;
		}

		if(flag==0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
} 
