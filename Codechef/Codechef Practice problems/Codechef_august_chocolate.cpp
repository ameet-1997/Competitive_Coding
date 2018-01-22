#include<stdio.h>

int main()
{
	//long int test,m,n,m1=1000000001,n1=1000000001,flag=0,i,j;
	long int test,m,n,m1=50,n1=50,flag=0,i,j;
	char a[m1][n1];
	
	a[1][1]=2;
	
	
	for(i=1;i<m1;++i)	//loop for the matrix
	{
		for( j=1;j<n1;++j)	//loop for the matrix
		{
			for(long int p=1;p<i;++p)	//memoization
			{
				if((a[p][j]==2)&&(a[i-p][j]==2))
				{
					flag=1;
					break;
				}
			}
			
			for(long int p=1;p<j;++p)	//memoization
			{
				if((a[i][p]==2)&&(a[i][j-p]==2))
				{
					flag=1;
					break;
				}
			}
					if(flag==1)
					{
						a[i][j]=1;
						
					}
					else if(flag==0)
					{
						a[i][j]=2;
						
					}
					
					flag=0;

		}
	
	}
	
	
	scanf("%ld",&test);	//taking input
	
	for(long int i=0;i<test;++i)	//loop for the test cases
	{
		scanf("%ld %ld",&m,&n);
		if(a[m][n]==1)
		{
			printf("Yes\n");
		}
		else if(a[m][n]==2)
		{
			printf("No\n");
		}
	}
}
