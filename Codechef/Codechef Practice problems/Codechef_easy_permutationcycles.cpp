#include<stdio.h>

int main()
{
	int n,a[1001],total=0,cycles=0,start,prev,next,i,temp,str=0;
	int a[5000];
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i])
	}
	prev=start=1;
	while(total!=n)
	{	temp=next;
	
		next=a[prev];
		
		prev=temp;
		
		a[next]=-1;
		
		total++;
		
		if(next=start)
		{
			cycles++;
			for(int j=start;j<=n;++j)
			{
				if(a[j]!=-1)
				{
					start=prev=j;
					break;
				}
			}
				
		}
	}
		
}
