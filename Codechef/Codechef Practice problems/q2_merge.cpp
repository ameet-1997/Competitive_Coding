/*
This program sorts the numbers using bubble sort

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{	void merge(int*,int,int);
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
	
	merge(a,0,n-1);
	
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}


void merge(int *a,int i,int j)
{
	int mid;
	int *b;	//Temporary array
	int p=0,q=0,count=0;	//Loop variables
	mid=(i+j)/2;
	
	b=(int*) malloc(sizeof(int)*(j-i+1));
	
	if(i==j)
	{
		return;
	}
	else
	{	
		p=i;
		q=mid+1;
		count=0;
		
		merge(a,i,mid);
		merge(a,mid+1,j);
		
		while((p<=mid)&&(q<=j))
		{
			if(a[p]<a[q])
			{
				b[count]=a[p];
				p++;
				count++;
			}
			else
			{
				b[count]=a[q];
				q++;
				count++;
			}
			
		}
		
		
		if(p<=mid)
		{
			while(p<=mid)
			{
				b[count]=a[p];
				p++;
				count++;
			}
		}
		
		else if(q<=j)
		{
			while(q<=j)
			{
				b[count]=a[q];
				q++;
				count++;
			}
		}
		
		for(p=0;p<(j-i+1);++p)
		{
			a[i+p]=b[p];
		}
		
		free(b);
		
		return;
		
		
		
	}
	
}
