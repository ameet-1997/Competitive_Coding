#include<stdio.h>

int main()
{	int n,*a;
	void merge(int *,int,int);
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	printf("\nEnter the numbers : ");
	a= new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	merge(a,0,n-1);
	printf("\nThe sorted array is : ");
	for(int i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	delete []a;
}


void merge(int *a,int start,int stop)
{	int pos,number,*b,i=start,j=(start+stop)/2+1,count=0,temp;
	b=new int [stop-start+1];
	if(stop==start)
	{
		return;
	}
	else if(stop==start+1)
	{
		if(a[start]>a[stop])
		{
			temp=a[start];
			a[start]=a[stop];
			a[stop]=temp;
		}
	}
	else
	{
		merge(a,start,(stop+start)/2);
		merge(a,(start+stop)/2+1,stop);
		
		while((i<=(start+stop)/2)&&(j<=stop))
		{
			if(a[i]<=a[j])
			{
				b[count]=a[i];
				count++;
				i++;
			}
			else
			{
				b[count]=a[j];
				count++;
				j++;
			}
		}
		if(i!=(start+stop)/2+1)
		{
			while(i!=(stop+start)/2+1)
			{
				b[count]=a[i];
				count++;
				i++;
			}
		}
		else
		{
			while(j!=stop+1)
			{
				b[count]=a[j];
				count++;
				j++;
			}
		}
		for(int k=0;k<=stop-start;++k)
		{
			a[start+k]=b[k];
		}
		delete []b;
		return;
	}
}



