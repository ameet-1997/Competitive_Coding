#include <stdio.h>

int main()
{
	int q;
	scanf("%d",&q);

	for(int zz=0;zz<q;zz++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);

		if(d%b == 0)
		{
			printf("%d\n",d/b);
		}
		else if(d%b == a)
		{
			printf("%d\n",d/b+1);
		}
		else if(d%b > a)
		{
			printf("%d\n",d/b+2);
		}
		else if(d%b < a)
		{	
			int n = d/b;
			if((a-d%b)%(b-a) == 0)
			{
				if((a-d%b)/(b-a) <= n)
				{
					printf("%d\n",d/b+1);			
				}
				else
				{
					printf("%d\n",d/b+2);			
				}
			}
			else
			{
				printf("%d\n",d/b+2);
			}
		}
	}
} 
