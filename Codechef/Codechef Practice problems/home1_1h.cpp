#include<stdio.h>

int main()
{
	int n;	//Size of the array
	int *a;	//Pointer for storing the array elements
	int i;	//Loop variable
	
	int max1,max2,maxi;	//Contains the maximum and the second maximum numbers
	
	scanf("%d",&n);	//Prompting user to enter the size of the array
	
	//a=(int *)malloc(n*sizeof(int));
	a=new int[n];
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);	//Prompting the user to enter the elements of the array
	}
}
