#include<stdio.h>

int main()
{
	void merge(long int *,long int,long int);
	int test;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		long int n,k,e,m,*score,temp,sum,sergey=0,target;
		scanf("%ld%ld%ld%ld",&n,&k,&e,&m);
		score=new long int[n-1];
		for(long int j=0;j<n-1;++j)
		{
			sum=0;
			for(long int k=0;k<e;++k)
			{
				scanf("%ld",&temp);
				sum=sum+temp;
				score[j]=sum;
			}
		}
		for(long int k=0;k<e-1;++k)
		{
			scanf("%ld",&temp);
			sergey=sergey+temp;
		}
		merge(score,0,n-2);
		if(score[k-1]!=score[k-2])
		{
			target=score[k-1]+1;
		}
		else
		{
			long int tr=k-2;
			while(score[tr]==score[k-1])
			{
				tr--;
			}
			target=score[tr];
		}
		
		if((target-sergey)<0)
		{
			printf("%ld\n",0);
			
		}
		else if((target-sergey)<=m)
		{
			printf("%ld\n",target-sergey);
		}
		else
		{
			printf("Impossible\n");
		}
		delete[] score;
	}
	
	
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
		if(a[start]<a[stop])/////////
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
			if(a[i]>=a[j])
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
		for(long int k=0;k<=stop-start;++k)
		{
			a[start+k]=b[k];
		}
		delete []b;
		return;
	}
}

