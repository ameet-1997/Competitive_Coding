/*
This program sorts the numbers using bubble sort

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	void quick(int*,int,int);
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
	
	quick(a,0,n-1);
	
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}


void quick(int *a,int i,int j)
{
	int pivot;	//To be used as the pivot element
	int p,q;	//Loop variables
	int temp;	//To perform a swap
	
	p=i+1;
	q=j;
	pivot=a[i];
	
	if(p>q)
	{
		return;
	}
	
	while(p<=q)
	{
		while((a[p]<pivot)&&(p<=j))
		{
			p++;
		}
		
		while(a[q]>pivot)
		{
			q--;
		}
		
		if(p<=q)
		{
			temp=a[p];
			a[p]=a[q];
			a[q]=temp;
			p++;
			q--;
		}		
		
	}
	
	temp=a[i];
    a[i]=a[q];
    a[q]=temp;
	
	
	quick(a,i,q-1);
	quick(a,q+1,j);
	return;
}
