#include<stdio.h>

int main()
{	
	void build_heap(int*,int);
	void propagate(int*,int);
	
	int n;	//Size of the array
	int *a;	//Pointer for storing the array elements
	int i;	//Loop variable
	int temp;
	
	int max1,max2;	//Contains the maximum and the second maximum numbers
	
	scanf("%d",&n);	//Prompting user to enter the size of the array
	
	//a=(int *)malloc(n*sizeof(int));
	a=new int[n+2];
	
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);	//Prompting the user to enter the elements of the array
	}
	if(n%2==0)
	{
		a[n+1]=-2147483648;	//Minimum number representable in int type to make the number of elements odd
		build_heap(a,n+1);
	}
	else
	{
		build_heap(a,n);
	}
	
	max1=a[1];	//The first three elements of the heap will contain the three maximum numbers and thus comparisons are used to find them
	
	
	
	printf("%d %d",max1,max2);
	delete[] a;
	
}


void build_heap(int* a,int n)
{	
	int parent,child=n,child1,child2,temp;
	parent=n/2;
	
	
	while(parent)
	{
		if((a[child]>a[parent])&&(a[child]>=a[2*parent]))	//The maximum value between children and parent is stored in parent
		{
			temp=a[parent];
			a[parent]=a[child];
			a[child]=temp;
		}
		else if((a[2*parent]>a[parent])&&(a[child]<a[2*parent]))	//The maximum value between children and parent is stored in parent
		{
			temp=a[parent];
			a[parent]=a[2*parent];
			a[2*parent]=temp;
		}
		child=child-2;
		parent=child/2;
	}
}
