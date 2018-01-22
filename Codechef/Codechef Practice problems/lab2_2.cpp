/*
This program prints the permutations of the given n numbers

Ameet S Deshpande
CS15B001
*/

#include<stdio.h>

int main()
{	

	void print(int*,int);
	long int fact(int);
	
	int a[14],b[14],number[14],buf[14];	//Stores the arrays and the indexes
	int n;		//Stores the size of the array
	int i;	//Loop variable
	long int counter;	//Loop Variable
	int pnt,count=0;
	int temp;
	int min;
	int index;
	
	scanf("%d",&n);
	counter=fact(n);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=i;
		number[i]=a[i];
	}
	
	while(counter)
	{	
		print(number,n);
		if(counter==1)
		{
			break;
		}
	
		pnt=n-1;
		while((b[pnt-1]>b[pnt])&&(pnt>=1))	//Traverse the array in backwards order till you encounter an adjacent smaller number
		{
			
			buf[count]=b[pnt];
			count++;
			pnt--;	//To get the value of pnt
			
		}
		
		
			buf[count]=b[pnt];
		
		
		
		for(i=pnt;i<=n-1;++i)	//Reconstruct the permuted array
		{
			b[i]=buf[i-pnt];
			//count--;
		}
		
		count=0;
		
		
		min=n-1;
		for(i=pnt;i<=n-1;++i)
		{
			if((b[i]<=min)&&(b[i]>=b[pnt-1]))
			{
				min=b[i];
				index=i;
			}
		}
		temp=b[pnt-1];
		b[pnt-1]=min;
		b[index]=temp;
		
		for(i=pnt;i<=n-1;++i)
		{
			if(b[i]==b[pnt-1])
			{
				b[i]=temp;
				break;
			}
		}		
		
		for(i=0;i<n;++i)
		{
			number[i]=a[b[i]];
		}
		
		
		counter--;
		
	}
	
	return 0;
	
}


void print(int* a,int n)	//Prints the contents of a given array
{	int i;
	for(i=0;i<n;++i)
	{
		printf("%d",a[i]);
	}
	printf(" ");
}


long int fact(int n)	//Calculates the factorial of the given number
{
	long int f=1;
	int i;
	for(i=1;i<=n;++i)
	{
		f=f*i;
	}
	
	return f;
}
