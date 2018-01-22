#include<stdio.h>
#include<math.h>

long int a[510049];
int main()
{
	long int test,n,b[510049],sieve=2,count=1,power=0,product=1;
	b[0]=2;
	while(sieve<=500000)
	{
		for(long int j=sieve;sieve*j<=510049;++j)
		{
			a[j*sieve]=1;
		}
		for(long int k=sieve+1;k<510049;++k)
		{
			if(a[k]=0)
			{	b[count]=k;
				count++;
				sieve=k;
				break;
			}
		}
	}
	
	scanf("%ld",&test);
	for(long int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		for(int i=0;b[i]<int(sqrt(n))+1;++i)
		{
			if(n%b[i]==0)
			{
				while(n%b[i]==0)
				{
					n=n/b[i];
					power++;
				}
				product=product*(power+1);
			}
			power=0;
		}
		if(product%2==0)
		{
			printf("%ld",(long int)pow(n,product/2));
		}
		else
		{
			printf("%ld",(long int)pow(n,(double(product)/2)));
		}
		product=1;
	}
	
	
}
