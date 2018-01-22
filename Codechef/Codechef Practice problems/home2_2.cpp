/*
This program prints all possible configurations of queens 
in an n*n chess board such that no 2 queens attack
each other

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>


int count=0;	//Global variable to count the number of configurations possible

int main()
{	void queen(int*,int,int);
	
	int n;	//Dimension of the chess board
	int a[12];	//Array to store the configurations 
	int i;	//Loop variable
	
	scanf("%d",&n);
	
	for(i=0;i<n;++i)
	{
		a[i]=0;
	}
	
	if(n==1)
	{
		printf("0");
	}
	else
	{
		queen(a,0,n);
		printf("%d",count);
	}
	
	return 0;
}



void queen(int *a,int j,int n)
{	int p,q;	//Loop variables	
	int flag=0;	//Flag to check which case the configuration falls in

	if(j==n-1)
	{
		for(p=0;p<n;++p)
		{
			a[j]=p;
			
			for(q=0;q<j;++q)	//If new column adds a 1 where there is already a 1 in the row, then dont print anything
			{
				if(a[q]==p)
				{
					flag=-1;
				}
			}
			
			for(q=0;q<j;++q)	//If it lies on one of the rightward inclined diagonal, then dont print anything
			{
				if((a[j]+j)==(a[q]+q))
				{
					flag=-1;
				}
			}
			
			
			for(q=0;q<j;++q)
			{
				if((a[j]-j)==(a[q]-q))	//If it lies on one of the rightward inclined diagonal, then dont print anything
				{
					flag=-1;
				}
			}
			
			if(flag==0)
			{
				for(q=0;q<=j;++q)	//If none of the above cases, then print
				{
					printf("%d ",a[q]);
				}
				count++;
				printf("\n");
			}
						
			flag=0;
			
		}
		
		return;
	}
	
	else
	{
		for(p=0;p<n;++p)
		{
			a[j]=p;
			
			for(q=0;q<j;++q)	//If new column adds a 1 where there is already a 1 in the row, then dont print anything
			{
				if(a[q]==p)
				{
					flag=-1;
				}
			}
			
			for(q=0;q<j;++q)	//If it lies on one of the rightward inclined diagonal, then dont print anything
			{
				if((a[j]+j)==(a[q]+q))
				{
					flag=-1;
				}
			}
			
			
			for(q=0;q<j;++q)
			{
				if((a[j]-j)==(a[q]-q))	//If it lies on one of the rightward inclined diagonal, then dont print anything
				{
					flag=-1;
				}
			}
			
			
			if(flag==0)
			{
				queen(a,j+1,n);
			}
			
			flag=0;
		}
	}
}
