#include<stdio.h>
#include<string.h>

int main()
{
	int dictionary,test,words,j=0,status;
	char english[100][21],minion[100][21],a,temp[21];
	scanf("%d",&dictionary);
	for(int i=0;i<dictionary;++i)
	{	fflush(stdin);
		while((a=getchar())!=' ')
		{
			english[i][j]=a;
			j++;
		}
		english[i][j]='\0';
		j=0;
		a=getchar();
		a=getchar();
		while((a=getchar())!='\n')
		{
			minion[i][j]=a;
			j++;
		}
		minion[i][j]='\0';
		j=0;
		
	}
	
	scanf("%d",&test);
	for(int ed=0;ed<test;++ed)
	{	int y=0;
		scanf("%d",&words);
		fflush(stdin);
		for(int k=0;k<words;++k)
		{	a=getchar();
			while((a!=' ')&&(a!='\n'))
			{
				temp[y]=a;
				y++;
				a=getchar();
			}
			temp[y]='\0';
			y=0;
			for(int l=0;l<dictionary;++l)
			{	int hi=0;
				status=1;
				while(temp[hi]!='\0')
				{
					if(temp[hi]!=english[l][hi])
					{
						status=0;
						break;
						
					}
					hi++;
				}
				if(status==1)
				{
					printf("%s ",minion[l]);	
					break;
				}	
			}
		
		}
		printf("\n");		
	}
	
	
	
}
