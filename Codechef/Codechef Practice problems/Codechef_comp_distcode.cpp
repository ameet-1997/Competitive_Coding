#include<stdio.h>
#include<string.h>

int main()
{
	int test,count=0,codes=0,flag=1;
	char a[10001],store[10000][2];
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%s",a);
		for(int j=0;a[j+1]!='\0';++j)
		{
			if((a[j]>='A')&&(a[j]<='Z')&&(a[j+1]>='A')&&(a[j+1]<='Z'))
			{
				for(int l=0;l<codes;++l)
				{
					if((store[l][0]==a[j])&&(store[l][1]==a[j+1]))
					{
						flag=0;
						break;
					}
				}
				if(flag!=0)
				{
					store[codes][0]=a[j];
					store[codes][1]=a[j+1];
					codes++;
				}
				else
				{
					flag=1;
				}
			}
		}
		printf("%d\n",codes);
		codes=0;
	}
}

/*	while((a[j]>='A')&&(a[j]<='Z')&&(a[j]!='\0'))
			{
				count++;
				j++;
			}
			codes=codes+count-1;
			count=0;
*/
