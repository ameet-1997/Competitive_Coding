#include<stdio.h>

int main()
{
	int n,*a,flag=1,majorflag=0;
	long int sum=0,k;
	scanf("%d",&n);
	a=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	sum=a[0];
	for(int i=0;i<n-1;++i)
	{	sum=sum+a[i];
		for(int j=i+1;j<n;j+=2)
		{
			sum=sum+a[j];
			k=sum*2/(j-i+1);
			for(int l=i;l<=j;++l)
			{
				for(int m=l+1;m<=j;++m)
				{
					if(a[l]+a[m]==k)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					
				}
			}
		}
	}
}
