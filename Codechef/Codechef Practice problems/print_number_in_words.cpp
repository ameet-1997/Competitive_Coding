#include<stdio.h>

int main()
{	void words(int *,int);
	void binary(int);
	void ternary(int);
	int n,*a;
	printf("Enter the number of digits in your number : ");
	scanf("%d",&n);
	a=new int[n];
	printf("Enter the digits one by one : ");
	int m=n-1;
	while(m>=0)
	{
		scanf("%d",&a[m]);
		m--;
	}
	words(a,n);
	delete[] a;
	
}

void words(int *a,int n)
{	void binary(int);
	void ternary(int);
	if(n>7)
	{
		words(a,n-7);
		printf(" crores");
	}
	
	if(!(a[6]*10+a[5])==0)
	{
		binary(a[6]*10+a[5]);
		printf(" lakhs ");	
	}
	
	if(!(a[4]*10+a[3])==0)
	{
		binary(a[4]*10+a[3]);
		printf(" thousand ");	
	}
	
	if(!(a[2]*100+a[1]*10+a[0])==0)
	{
		ternary(a[2]*100+a[1]*10+a[0]);	
	}
	
	
}

void binary(int n)
{
	int m=n/10;
	switch(m)
	{
		case 2: printf(" twenty ");
				break;
		case 3: printf(" thirty ");
				break;
		case 4: printf(" forty ");
				break;
		case 5: printf(" fifty ");
				break;
		case 6: printf(" sixty ");
				break;
		case 7: printf(" seventy ");
				break;
		case 8: printf(" eighty ");
				break;
		case 9: printf(" ninety ");
				break;
	}
	
	if(m==1)
	{
		switch(n%10)
		{
			case 1: printf("eleven");
					break;
			case 2: printf("twelve");
					break;
			case 3: printf("thirteen");
					break;
			case 4: printf("fourteen");
					break;
			case 5: printf("fifteen");
					break;
			case 6: printf("sixteen");
					break;
			case 7: printf("seventeen");
					break;
			case 8: printf("eighteen");
					break;
			case 9: printf("nineteeen");
					break;
		}
	}
	
	else
	{
		switch(n%10)
		{
			case 1: printf("one");
					break;
			case 2: printf("two");
					break;
			case 3: printf("three");
					break;
			case 4: printf("four");
					break;
			case 5: printf("five");
					break;
			case 6: printf("six");
					break;
			case 7: printf("seven");
					break;
			case 8: printf("eight");
					break;
			case 9: printf("nine");
					break;
		}	
	}
}

void ternary(int n)
{
	switch(n/100)
		{
			case 1: printf("one hundred");
					break;
			case 2: printf("two hundred");
					break;
			case 3: printf("three hundred");
					break;
			case 4: printf("four hundred");
					break;
			case 5: printf("five hundred");
					break;
			case 6: printf("six hundred");
					break;
			case 7: printf("seven hundred");
					break;
			case 8: printf("eight hundred");
					break;
			case 9: printf("nine hundred");
					break;
			
	}
	
	binary(n%100);
}
