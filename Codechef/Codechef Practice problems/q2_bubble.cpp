/*
This program sorts the numbers using bubble sort

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	void bubble(int*,int);
	int n;	//To store the number of elements
	int *a;
	int i,j;	//Loop variable
	int temp;	//Temp variable for swapping
	
	scanf("%d",&n);
	
	a=(int *) malloc(sizeof(int)*n);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	
	bubble(a,n);
	
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}


void bubble(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;++i)
	{
		for(j=0;j<=n-2-i;++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
