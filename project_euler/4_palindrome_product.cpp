#include <stdio.h>

int check[1000000];

int main()
{	
	int check_palindrome(int);
	int test;
	scanf("%d",&test);

	for(int i=0;i<test;++i)
	{
		int n;
		scanf("%d",&n);


		for(int j=n-1;j>=101101;--j)
		{
			if(check[j] == 0)
			{
				check[j] = check_palindrome(j);
			}

			if(check[j] == 1)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
} 





int check_palindrome(int number)
{
	int number1 = number,number2 = 0;

	while(number1)
	{
		number2 = number2*10 + number1%10;
		number1 = number1/10;
	}

	if(number==number2)
	{
		int flag = -1;
		for(int i=100;i<=999;++i)
		{
			if(number%i == 0)
			{
				if((number/i >= 100)&&(number/i <=999))
				{
					flag = 1;
					break;
				}
			}
		}

		return flag;

	}
	else
	{
		return -1;
	}

}