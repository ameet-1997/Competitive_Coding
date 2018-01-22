/*
This program sorts the numbers using selection sort

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{	void selection(int*,int);
	int n;	//To store the number of elements
	int *a;
	int min,min_j;	//Stores the value of min in every iteration
	int i,j;	//Loop variable-
	int temp;	//Temp variable for swapping
	
	scanf("%d",&n);
	
	a=(int *) malloc(sizeof(int)*n);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	
	/*for(i=0;i<n;++i)
	{
		min=a[i];
		min_j=i;
		for(j=i;j<n;++j)
		{
			if(a[j]<min)
			{
				min_j=j;
				min=a[j];
			}
			
		}
		
		temp=a[i];
		a[i]=min;
		a[min_j]=temp;
	}*/
	selection(a,n);
	
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}

void selection(int *a,int n)
{	
	int i,j,min,min_j,temp;
	for(i=0;i<n;++i)
	{
		min=a[i];
		min_j=i;
		for(j=i;j<n;++j)
		{
			if(a[j]<min)
			{
				min_j=j;
				min=a[j];
			}
			
		}
		
		temp=a[i];
		a[i]=min;
		a[min_j]=temp;
	}
}
