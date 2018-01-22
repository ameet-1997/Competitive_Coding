#include <stdio.h>

int main()
{
	long long int test;
	scanf("%lld",&test);

	for(long long int i=0;i<test;++i)
	{
		long long int n;

		scanf("%lld",&n);

		long long int sum = 0;

		long long int temp_odd = 1;
		long long int temp_even = 2;
		long long int temp1,temp2;

		while(temp_even <= n)
		{	
			sum = sum + temp_even;
			temp1 = 3*temp_even + 2*temp_odd;
			temp2 = 2*temp_even + temp_odd;

			temp_even = temp1;
			temp_odd = temp2;
		}


		printf("%lld\n",sum);
	}
} 
