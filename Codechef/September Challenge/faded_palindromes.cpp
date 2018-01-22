#include <stdio.h>
#include <string.h>

int main()
{
	char a[13000];
	int test;
	scanf("%d",&test);

	for(int i=0;i<test;++i)
	{
		scanf("%s",a);
		int len=strlen(a);

		int end=len-1,flag=1;

		for(int j=0;j<=(len-1)/2;++j)
		{
			if((a[j]==a[end]))
			{
				if(a[j]=='.')
				{
					a[j]=a[end]='a';
				}

			}

			else if(a[j]=='.')
			{
				a[j]=a[end];
			}

			else if(a[end]=='.')
			{
				a[end]=a[j];
			}

			else
			{
				flag=0;
				break;
			}

			end--;
			

		}

		if(flag==0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%s\n",a);
		}
	}
}
 
