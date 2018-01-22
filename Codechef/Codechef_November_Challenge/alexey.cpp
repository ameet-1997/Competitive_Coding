#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

int main()
{	
	long long int gcd(long long int,long long int);

	long long int test;

	scanf("%lld",&test);
	long long int *a;

	for(long long int zz=0;zz<test;++zz)
	{
		long long int n;
		scanf("%lld",&n);
		a = (long long int*) malloc(sizeof(long long int)*n);

		for(long long int i=0;i<n;++i)
		{
			scanf("%lld",&a[i]);
		}

		long long int min = 100000000000000;

		for(long long int i=0;i<n;++i)
		{
			for(long long int j=i+1;j<n;++j)
			{
				long long int temp;

				if(a[i] > a[j])
				{
					temp = gcd(a[i],a[j]);	
				}
				else
				{
					temp = gcd(a[j],a[i]);	
				}

				//printf("temp : %lld\n",temp);
				

				temp = a[i]*a[j]/temp;

				if(temp < min)
				{
					min = temp;
				}
			}
		}

		printf("%lld\n",min);

		free(a);

	}
} 


long long int gcd(long long int a,long long int b)
{
	if(a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}
