/*
Cinstructing a MIN Heap

Ameet S Deshpande
CS15B001
*/

#include <stdio.h>

int main()
{	
	void build_heap(int*,int);
	int n;
	int a[1001];
	scanf("%d",&n);	//Take total number of elements as input
	for(int i=1;i<=n;++i)	//1-based indexing
	{
		scanf("%d",&a[i]);
	}

	build_heap(a,n);

	for(int i=1;i<=n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
} 


void build_heap(int *a,int n)
{	
	void put_correct_place(int*,int,int);
	int temp;
	for(int i = n;i>=2;--i)
	{
		if(a[i] < a[i/2])
		{
			temp = a[i];
			a[i] = a[i/2];
			a[i/2] = temp;
			put_correct_place(a,n,i);
		}
	}
}

void put_correct_place(int *a,int n,int i)
{	
	int temp;
	if(2*i > n)
	{
		return;
	}

	else if(2*i + 1 > n)
	{
		if(a[i*2] < a[i])
		{
			temp = a[i];
			a[i] = a[i/2];
			a[i/2] = temp;
			put_correct_place(a,n,2*i);
		}
		return;
	}
	else
	{
		int min_index = i;
		if(a[i*2] < a[i])
		{
			min_index = 2*i;
		}
		if(a[i*2+1] < a[min_index])
		{
			min_index = 2*i+1;	
		}

		if(min_index!=i)
		{
			temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;

			put_correct_place(a,n,min_index);
			return;	
		}
		
		return;
	}
}