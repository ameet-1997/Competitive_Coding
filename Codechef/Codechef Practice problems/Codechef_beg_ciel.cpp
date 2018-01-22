#include<stdio.h>

int main()
{
	int test,p,j,price=1,count=0,temp;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&p);
		while(p!=0)
		{
			for(int j=0;j<12;++j)
			{
				if(price>p)
				{
					break;
				}
				price=price*2;
			}
			if(price>2048)
			{
				temp=p/2048;
				count=count+temp;
				p=p-temp*2048;
				price=1;
			}
			else
			{
				p=p-price/2;
				price=1;
				count++;
			}
		}
		
		printf("%d\n",count);
		count=0;
	}			
}
