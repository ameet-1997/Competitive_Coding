//Memoization
#include<stdio.h>

short int a[100][100],max[100][100];
int main()
{	long int maxsum(int,int,int);
	int test,lines;
	for(int l=0;l<100;++l)
	{
		for(int m=0;m<100;++m)
		{
			max[l][m]=-1;
		}
	}
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&lines);
		for(int j=0;j<lines;++j)
		{
			for(int k=0;k<j+1;++k)
			{
				scanf("%d",&a[j][k]);
			}
		}
		printf("%ld\n",maxsum(0,0,lines));
		for(int l=0;l<100;++l)
		{
			for(int m=0;m<100;++m)
			{
				max[l][m]=-1;
			}
		}
		
	}
}

long int maxsum(int i,int j,int lines)
{	long int c,b;
	if(i==lines-1)
	{
		return a[i][j];
	}
	else
	{	if(max[i+1][j]!=-1)
		{	
			c=max[i+1][j];
		}
		else
		{
			c=maxsum(i+1,j,lines);	
		}
		if(max[i+1][j+1]!=-1)
		{
			b=max[i+1][j+1];
		}
		else
		{
			b=maxsum(i+1,j+1,lines);	
		}
	
		if(c>b)
		{	max[i][j]=c+a[i][j];
			return (max[i][j]); 
		}
		else
		{
			max[i][j]=b+a[i][j];
			return (max[i][j]);
		}		
	}
}
