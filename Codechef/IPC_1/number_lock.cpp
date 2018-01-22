#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int *a,*sum;

	a = (int*) malloc(sizeof(int)*n);
	sum = (int*) malloc(sizeof(int)*n);

	for( int i = 0;i < n; ++i )
	{
		a[i] = sum[i] = 0;
	}

	for(int i=0;i<q;++i)
	{
		int type,l,r;
		scanf("%d %d %d",&type,&l,&r);
		
		l=l-1;
		r=r-1;

		if(type == 2)
		{
			int answer=0;
			for(int j=l;j<=r;++j)
			{
				answer = answer+a[j];
			}
			printf("%d\n",answer);
		}

		else	//If type == 1
		{
			for( int j = l;j <= r; ++j )
			{
				if(a[j]==9)
				{
					a[j]=0;
				}
				else
				{
					a[j]=a[j]+1;
				}

				/*if(j==0)
				{
					sum[j]=a[j];
				}
				else
				{
					sum[j]=sum[j-1]+a[j];
				}*/
			}
		}
	}
} 
