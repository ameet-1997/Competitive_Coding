#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		int n;
		scanf("%d",&n);
		int tie = 0;
		int index,max=0;

		for(int j = 0;j < n; ++j)
		{	
			int type[7] = {0,0,0,0,0,0,0};
			int c;
			int points = 0;
			int temp;
			


			scanf("%d",&c);

			for(int k = 0; k < c ;++k)
			{
				scanf("%d",&temp);
				type[temp]++;
			}

			points=c;

			/*
			Sorting the elements
			*/

			for(int l=0;l<7;++l)
			{
				for(int m=0;m<=7-2-l;++m)
				{
					if(type[m]>type[m+1])
					{
						temp=type[m];
						type[m]=type[m+1];
						type[m+1]=temp;
					}
				}
			}

			points=points+4*type[1]+2*(type[2]-type[1])+type[3]-type[2];

			if(points>max)
			{
				max=points;
				index=j;
				tie=0;
			}
			else if(points==max)
			{
				tie=1;
			}




		}

		if(tie==1)
		{
			printf("tie\n");
		}
		else if(index==0)
		{
			printf("chef\n");
		}
		else
		{
			printf("%d\n",index+1);
		}
	}
} 
