#include <stdio.h>

/*int main()
{
	int test;
	int check[1500];
	int flag;

	scanf("%d",&test);

	for(int i=2;i<1500;++i)
	{
		check[i]=i*(i+1)/2;
	}

	for(int i=0;i<test;++i)
	{
		int n;
		flag=0;

		scanf("%d",&n);
		if(n%2==1)
		{
			printf("Yes\n");
		}
		else if((n==1)||(n==2))
		{
			printf("No\n");
		}
		else
		{
			for(int j=2;(j<1500)&&(n>check[j]);++j)
			{
				if(((n-check[j])%j)==0)
				{
					flag=1;
					break;
				}
			}

			if(flag==1)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}

	
}*/

int main()
{
	long int a[30];
	long int ans=1;
	for(int i=0;i<30;++i)
	{
		a[i]=ans;
		ans=ans*2;
	}

	int test;
	scanf("%d",&test);

	for(int i=0;i<test;++i)
	{
		int n,flag=0;
		scanf("%d",&n);

		for(int j=0;j<30;++j)
		{
			if(a[j]==n)
			{
				flag=1;
				break;
			}
		}

		if(flag==1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}


