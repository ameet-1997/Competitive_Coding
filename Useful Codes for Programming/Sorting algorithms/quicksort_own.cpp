#include<stdio.h>

int *a;
int n;

int main()
{	
	void quicksort(int,int);
	
	printf("Enter the number of elements you want to enter : ");
	scanf("%d",&n);
	a=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	
	printf("The sorted elements are : ");
	for(int i=0;i<n;++i)
	{
		printf("  %d  ",a[i]);
	}
	delete[] a;
	return 0;
}



void quicksort(int l,int r)
{	
	int i=l+1,temp,pivot;
	pivot=a[l];
	if(l>=r)
	{
		return;
	}
	else
	{
		for(int j=l+1;j<=r;++j)
		{
			if(a[j]<=pivot)
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				i++;
			}
		}
		temp=a[l];
		a[l]=a[i-1];
		a[i-1]=temp;
		quicksort(l,i-1);
		quicksort(i,r);
		return;
	}
}
