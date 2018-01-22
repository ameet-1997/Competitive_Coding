#include <stdio.h>
	

//Change to long long long int	////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	long long int test;

	scanf("%lld",&test);

	for(long long int i=0;i<test;++i)
	{
		long long int minus=0,plus=0,zeros=0,other=0;

		long long int n;

		scanf("%lld",&n);

		long long int temp;	//To store the numbers

		for(long long int j=0;j<n;++j)
		{
			scanf("%lld",&temp);
			if(temp == -1)
			{
				minus++;
			}
			else if(temp == 0)
			{
				zeros++;
			}
			else if(temp == 1)
			{
				plus++;
			}
			else
			{
				other++;
			}
		}

		if(other >= 2)
		{
			printf("no\n");
		}
		else if(other == 1)
		{
			if(minus > 0)
			{
				printf("no\n");
			}
			else
			{
				printf("yes\n");
			}
		}
		else if(other == 0)
		{
			if((zeros == 0)&&(plus == 0))
			{
				if(minus == 1)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else if(plus == 0)
			{
				if(minus <= 1)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else
			{
				printf("yes\n");
			}
		}

	}

	return 0;
} 
