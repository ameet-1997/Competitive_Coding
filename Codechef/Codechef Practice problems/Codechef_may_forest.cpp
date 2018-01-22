/*
#include<stdio.h>

int main()
{
	long int n,w,l,*h,*r,total=0,months=0;
	scanf("%ld%ld%ld",&n,&w,&l);
	h=new long int[n];
	r=new long int[n];
	
	for(int i=0;i<n;++i)
	{
		scanf("%ld%ld",&h[i],&r[i]);
	}
	
	while(1)
	{
		for(int i=0;i<n;++i)
		{
			if(h[i]>=l)
			{
				total=total+h[i];
			}
			h[i]=h[i]+r[i];
		}
		
		if(total>=w)
		{
			printf("%ld",months);
			break;
		}
		total=0;
		months++;
	}
	delete[] h;
	delete[] r;
	return 0;	
}
*/




#include<stdio.h>

int main()
{
	long long int n,w,l,*h,*r,total=0,months=0;
	scanf("%lld%lld%lld",&n,&w,&l);
	h=new long long int[n];
	r=new long long int[n];
	
	for(int i=0;i<n;++i)
	{
		scanf("%lld%lld",&h[i],&r[i]);
	}
	
	while(1)
	{
		for(int i=0;i<n;++i)
		{
			if(h[i]>=l)
			{
				total=total+h[i];
			}
			h[i]=h[i]+r[i];
		}
		
		if(total>=w)
		{
			printf("%lld",months);
			break;
		}
		total=0;
		months++;
	}
	delete[] h;
	delete[] r;
	return 0;	
}
