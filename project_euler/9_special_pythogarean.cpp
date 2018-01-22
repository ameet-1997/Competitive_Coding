#include <stdio.h>
#include <math.h>

int main()
{
	long long int from = sqrt(500) + 1;

	long long int a = 0,b = 0;

	for(long long int j=from;j>=1;--j)
	{
		if(500%j == 0)
		{
			if(500/j-j > 0)
			{	
				a = j;
				b = 500/j-j;
				break;
			}
		}
	}


	printf("%lld\n",(a*a*a*a-b*b*b*b)*2*a*b);
} 
