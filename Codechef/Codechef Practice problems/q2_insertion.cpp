/*
This program sorts the numbers using bubble sort

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{	void insertion(int*,int);
	int n;	//To store the number of elements
	int *a;
	int i,j,q;	//Loop variable
	int temp;	//Temp variable for swapping
	
	scanf("%d",&n);
	
	a=(int *) malloc(sizeof(int)*n);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	
	
	insertion(a,n);
	
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}

void insertion(int *a,int n)
{	int i,j,temp,q;
	for(i=0;i<n;++i)
	{
		for(j=0;j<i;++j)
		{
			if(a[j]>a[i])
			{
				break;
			}
		}
		
		temp=a[i];
		
		for(q=i;q>=j+1;--q)
		{
			a[q]=a[q-1];
		}
		
		a[j]=temp;
	}
}
