#include <stdio.h>

int main()
{
	int test;

	scanf("%d",&test);

	for(int i=0;i<test;++i)
	{
		int x1,y1,x2,y2;

		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

		if(x1 == x2)
		{
			if(y2>y1)
			{
				printf("up\n");
			}
			else
			{
				printf("down\n");
			}
		}
		else if(y1 == y2)
		{
			if(x2 > x1)
			{
				printf("right\n");
			}
			else
			{
				printf("left\n");
			}
		}
		else
		{
			printf("sad\n");
		}

	}
} 
