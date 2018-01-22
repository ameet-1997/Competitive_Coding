#include <stdio.h>
#define mod 1000000007

long long answer[1000000];

int main()
{	
	long long check_left(long long);
	long long combination(long long n,long long r);
	long long heap_number(long long);
	long long factorial(long long);


	answer[0] = 1;
	answer[1] = 1;
	answer[2] = 1;

	for(long long i = 3; i<=100000 ; ++i)
	{
		answer[i] = heap_number(i);
	}

	printf("done\n");

	long long test;
	scanf("%lld",&test);


	for(long long zz = 0;zz<test;++zz)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);

		if(heap_number(n) == m)
		{
			printf("correct\n");
		}
		else
		{
			printf("incorrect\n");
		}
	}
}



long long check_left(long long n)
{
	long long power = 1;

	while(power-1 < n)
	{
		power = power*2;
	}

	if( power-1 == n)
	{
		return (n-1)/2;
	}
	else
	{
		power = power/2;
		long long sum = 0;
		sum = (power-2)/2;
		long long check = n - (power-1);

		if(check >= power/2)
		{
			return power/2+sum;
		}
		else
		{
			return check+sum;
		}
	}

}

long long heap_number(long long n)
{	long long combination(long long,long long);

	printf("%lld\n",n);
	if(answer[n] != 0)
	{
		return answer[n];
	}

	else
	{
		long long left = check_left(n);
		long long right = n - 1 - left;

		long long ret1 = heap_number(left)%mod;
		long long ret2 = heap_number(right)%mod;

		long long ret = (ret1 + ret2)%mod;

		answer[n] = ret = (combination(n,left)*ret)%mod;
		return ret;
	}
} 


long long combination(long long n, long long r)
{	
	long long factorial(long long);
	long long result;
 
   result = factorial(n)/(factorial(r)*factorial(n-r));
 
   return result;
}

long long factorial(long long n)
{
	long long c;
   long long result = 1;
 
   for (c = 1; c <= n; c++)
      result = result*c;
 
   return result;
}
