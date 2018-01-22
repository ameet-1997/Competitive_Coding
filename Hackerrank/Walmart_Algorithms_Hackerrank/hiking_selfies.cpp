#include <stdio.h>

int main()
{	
	int calculate_power(int);

	int n,x;

	scanf("%d %d",&n,&x);

	int required = calculate_power(n);
	required = required - 1;

	if(x > required)
	{
		printf("%d\n",x-required);
	}
	else
	{
		printf("%d\n",required-x);
	}
} 



int calculate_power(int n)
{
	int product = 1;

	while(n > 0)
	{
		product = product*2;
		n--;
	}

	return product;
}
