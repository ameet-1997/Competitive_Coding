#include <stdio.h>

int main()
{
	int n,m;
	int a[10],b[10];
	scanf("%d %d",&n,&m);

	int max_a = 0,min_b = 200;

	for(int i=0;i<n;++i)
	{	
		scanf("%d",&a[i]);
		if(a[i] > max_a)
		{
			max_a = a[i];
		}
	}

	for(int i=0;i<n;++i)
	{
		scanf("%d",&b[i]);
		if(b[i] < min_b)
		{
			min_b = b[i];
		}
	}


	int count = 0;

	//for(int i=max_a;i<=min_b;++i)
	for(int i=1;i<=100;++i)
	{	
		int flag1 = 1;
		for(int j=0;j<n;++j)
		{
			if( i%a[j]!=0 )
			{
				flag1 = 0;
				break;
			}
		}

		for(int j=0;j<m;++j)
		{
			if( b[j]%i != 0)
			{
				flag1 = 0;
				break;
			}
		}

		if(flag1 == 1)
		{
			count++;
		}
	}

	printf("%d\n",count );



} 
