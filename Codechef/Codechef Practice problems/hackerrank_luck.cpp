#include<stdio.h>

int main()
{	

	void merge(long int *,long int,long int);
	
	long int n,k,*l,luck=0,temp_l,temp_t;
	long int i,count=0;
	scanf("%ld%ld",&n,&k);
	l=new long int[n];
	for(i=0;i<n;++i)
	{
		scanf("%ld%ld",&temp_l,&temp_t);
		if(temp_t==0)
		{
			luck=luck+temp_l;
		}
		
		else
		{
			l[count]=temp_l;
			count++;
		}
	}
	count=count-1;
	
	merge(l,0,count);
	
	for(i=count;i>=count-k+1;--i)
	{
		luck=luck+l[i];
	}
	for(i=0;i<=count-k;++i)
	{
		luck=luck-l[i];
	}
	
	printf("%ld",luck);
	
	delete []l;
	return 0;
}



void merge(long int *a,long int start,long int stop)
{	long int pos,number,*b,i=start,j=(start+stop)/2+1,count=0,temp;
	b=new long int [stop-start+1];
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



