#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	long int test;
	scanf("%ld",&test);

	for(long int i=0;i<test;++i)
	{
		long int n,m,c;
		scanf("%ld%ld%ld",&n,&m,&c);
		long int count = 0;
		long int start_value;

		if(c/m < 1)
		{
			start_value = 1;
		}
		else
		{
			if(c%m == 0)
			{
				start_value = c/m;
			}
			else
			{
				start_value = c/m + 1;
			}
		}

		for(long int j=start_value;j<=n;++j)
		{
			if(c%j == 0)
			{
				count++;
			}
		}

		printf("%ld\n",count);
	}
} 
