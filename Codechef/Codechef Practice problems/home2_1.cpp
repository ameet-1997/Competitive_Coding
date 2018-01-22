/*
This program calculates the determinant of a given 
square matrix of integers

Ameet S Deshpande
CS15B001
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{	
	long int det(int* ,int,int,int,int);
	int n;	//Contains the dimension of the matrix
	int *a;	//The array that holds the value
	int i,j;	//Loop variable
	long int ans;	//Contains the determinant value
	
	scanf("%d",&n);	//Prompt the user for dimension of the square matrix
	
	//a=new int[2*n*n];	//Dyanamic allocation to create a n*2n array
	a=(int *) malloc(2*n*n*sizeof(int));	//Dyanamic allocation to create a n*2n array
	
	for(i=0;i<n;++i)	//Take the values of the matrix
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&a[2*n*i+j]);
			a[(2*n*i+j+n)]=a[2*n*i+j];	//if m is the matrix, [m m] is stored
		}
	}
	
	ans=det(a,n,0,0,n);
	printf("%ld",ans);	//Change \n
	//delete[] a;
	free(a);
	return 0;
	
}




long int det(int* b,int dim,int i,int j,int n)
{	
	int count;	//Loop variable
	int sign=1,sign2=1;
	long int sum=0;
	int *a;
	int p,q;
	int par;
	
	if(dim==1)
	{	
		return b[2*(dim+1)*i+j];
	}
	
	//a=new int[dim*2*dim];
	a=(int *) malloc(dim*2*dim*sizeof(int));
	
	if(dim!=n)
	{
		par=dim+1;
	}
	else
	{
		par=dim;
	}
	
	for(p=i;p<i+dim;++p)	//Take the values of the matrix
	{
		for(q=j;q<dim+j;++q)
		{
			a[2*dim*(p-i)+(q-j)]=b[2*par*p+q];
			a[(2*dim*(p-i)+(q-j)+dim)]=b[2*par*p+q];	//if m is the matrix, [m m] is stored
		}
	}
	
	/*for(p=0;p<dim;++p)	//Take the values of the matrix
	{
		for(q=0;q<2*dim;++q)
		{
			printf("%d ",a[2*dim*p+q]);
			
		}
		printf("\n");
	}*/
	
	
	j=0;
	i=0;
	
	
		count=dim;
		while(count)
		{
						
			if(((dim-1)%2==0)&&(j!=0)&&(j!=dim-1))
			{
				sign2=-1;
			}
			else
			{
				sign2=1;
			}
			
			sum=sum+sign*sign2*a[2*i*dim+j]*det(a,dim-1,i+1,j+1,n);
			
			
			j++;
			count--;
			sign=sign*-1;
		}
		
		free(a);
		//delete[] a;
		return sum;
		
}
