#include<stdio.h>
#include<math.h>

#define sum(x) x*(x+1)/2

int main()
{
	long int test,input,n;
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%ld",&input);
		n=sqrt(input*2)+1;
		while(n)
		{
			if (sum(n)<=input)
			{
				printf("%ld\n",n);
				break;
			}
			n--;
		}
	}
}
