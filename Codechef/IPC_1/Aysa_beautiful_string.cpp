#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	int **a,**b;

	char temp[1002];

	a = (int**) malloc(n1*sizeof(int*));
	b = (int**) malloc(n2*sizeof(int*));


	for (int i = 0; i < n1; ++i)
	{
		a[i] = (int*) malloc(sizeof(int)*26);
		
		for(int j=0;j<26;++j)
		{
			a[i][j]=0;
		}

		scanf("%s",temp);
		for(int j=0;temp[j]!='\0';++j)
		{
			a[i][(int)(temp[j])-65]++;
		}
	}

	
	for (int i = 0; i < n2; ++i)
	{
		b[i] = (int*) malloc(sizeof(int)*26);
		
		for(int j=0;j<26;++j)
		{
			b[i][j]=0;
		}

		scanf("%s",temp);
		for(int j=0;temp[j]!='\0';++j)
		{
			b[i][(int)(temp[j])-65]++;
		}
	}


	int answer = 0;

	for(int i=0;i<n1;++i)
	{
		for(int j=0;j<n2;++j)
		{	
			int flag= 0;
			for(int k=0;k<26;++k)
			{	
				if((a[i][k]==0)&&(b[j][k]==0))
				{
					flag=1;
					break;
				}
			}

			if(flag==0)
			{
				answer++;
			}
		}
	}

	printf("%d\n",answer);

	for(int i=0;i<n1;++i)
	{
		free(a[i]);
	}
	for(int i=0;i<n2;++i)
	{
		free(b[i]);
	}

	free(a);
	free(b);

	return 0;
} 
