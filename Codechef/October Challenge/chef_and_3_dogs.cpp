#include <stdio.h>
#include <iostream>

int main()
{
	long int test;
	scanf("%ld",&test);

	for(long int i=0;i<test;++i)
	{
		long int s,v;
		double answer;
		scanf("%ld %ld",&s,&v);
		answer = (((double)s*2.000000000)/(v*3.000000000));
		printf("%.8f\n",answer);

	}
}

