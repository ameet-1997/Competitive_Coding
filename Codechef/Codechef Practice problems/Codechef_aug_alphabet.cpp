#include<stdio.h>

int main()
{
	int read[27];
	int flag=0;
	
	for(int i=0;i<27;++i)
	{
		read[i]=0;
	}
	
	char words[26];
	scanf("%s",words);
	
	for(int i=0;words[i]!='\0';++i)
	{
		read[(int)(words[i])-97]++;
	}
	
	int n;
	scanf("%d",&n);
	char test[13];
	
	while(n>0)
	{
		scanf("%s",test);
		for(int i=0;test[i]!='\0';++i)
		{
			if(read[(int)(test[i])-97]==0)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
		
		flag=0;
		n--;
		
		
	}
}
