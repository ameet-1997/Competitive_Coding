#include<stdio.h>
int main()
{
	long int m,test,temp,remove;
	long long int n1,n2;
	scanf("%ld",&test);
	
	for(long int i=0;i<test;++i)
	{
		scanf("%lld%lld%ld",&n1,&n2,&m);
		if(n1<n2)
		{
			temp=n1;
			n1=n2;
			n2=temp;
		}
		
			remove=m;
			while((n2>=remove)&&(remove>=1))
			{
				n1=n1-remove;
				n2=n2-remove;
				remove=remove-1;
			}
			if(remove>1)
			{
				printf("%lld\n",n1-n2);
			}
			else
			{
				printf("%lld\n",n1+n2);
			}
				
	}
}
