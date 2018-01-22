#include<stdio.h>

int main()
{
	void merge(int *a,int,int);
	int test,n,k1,k2,k3,*a,*sum,count=0,total=0;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&n);
		scanf("%d",&k1);
		scanf("%d",&k2);
		scanf("%d",&k3);
		
		a=new int[n];
		sum=new int[n*(n+1)/2];
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a[j]);
		}
		
		for(int i=0;i<n;++i)
		{
			for(int j=i;j<n;++j)
			{
				total=total+a[j];
				sum[count]=total;
				count++;
			}
			total=0;
		}
		count=0;
		
		int temp=n*(n+1)/2;
		merge(sum,0,temp-1);
		printf("%d %d %d\n",sum[temp-k1],sum[temp-k2],sum[temp-k3]);
		
		delete[] a;
		delete[] sum;
	}
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
