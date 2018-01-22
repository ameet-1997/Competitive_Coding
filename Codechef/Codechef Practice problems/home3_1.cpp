/*
This program prints the elements of an array in sorted
order using counting sort
Ameet S Deshpande
CS15B001
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,k;	//Stores the number of elements in the array
	int *a,*count;	//Arrays used for storing variables and for counting respectively
	int i,j,l;	//Loop variables
	int min,max;
	
	scanf("%d",&n);
	scanf("%d",&k);
	
	a=(int *) malloc(sizeof(int)*n);
	
	if(n!=0)
	{
		scanf("%d",&a[0]);
		max=a[0];
		min=a[0];
		
		for(i=1;i<n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
			{
				min=a[i];
			}
			else if(a[i]>max)
			{
				max=a[i];
			}
		}
		
		
		count=(int*) malloc(sizeof(int)*(max-min+1));
		
		for(i=0;i<=max-min;++i)
		{
			count[i]=0;
		}
		
		for(i=0;i<n;++i)
		{
			count[a[i]-min]++;
		}
		
		for(i=0;i<=max-min;++i)
		{
			l=count[i];
			while(l>0)
			{
				printf("%d ",i+min);
				l--;
			}
		}
		printf("\n");
		
		free(a);
		free(count);
		
		
	}
	
	return 0;
	
	
}
