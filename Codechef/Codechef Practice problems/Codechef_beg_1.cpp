#include<stdio.h>

int main()
{   int minproduct(int,int);
	int n,k,value;
	printf("Enter the values of n and k in that order : ");
	scanf("%d%d",&n,&k);
	value=minproduct(n,k);
	printf("The answer is : %d",value);
}

int minproduct(int n,int k)
{	int minnext(int*,int,int);
	int* a;
	a=new int[n];
	if(n<=k)
	{	delete[] a;
		return n;
	}
	
	else
	{
		for(int i=n-k;i<n;++i)
		{
		a[i]=i*n;
		}
		for( int j=n-k-1;j>=1;--j)
		{
			a[j]=j*minnext(a,j,k);
		}
		
	}
	
	return a[1];
}

int minnext(int* a,int i,int k)
{	int min=a[i+1];
	for(int j=i+1;j<=i+k;++j)
	{
		if(a[j]<min)
		{
			min=a[j];
		}
	}
	return min;
}


