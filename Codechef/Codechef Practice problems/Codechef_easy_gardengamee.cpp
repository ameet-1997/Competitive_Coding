#include<stdio.h>

int main()
{	
	long int find_lcm(long int*,long int);
	long int test,*a,*b,size=0,total=0,current=0,temp;
	scanf("%ld",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%ld",&n);
		a=new int[n];
		for(int j=0;j<n;++j)
		{
			scanf("%ld",&a[j]);
		}
		
		for(int j=0;j<n;++j)
		{	if(a[j]==-1)
			{
				continue;
			}
			current=a[j];
			while(a[current]!=a[j])
			{
				temp=current;
				current=a[current];
				a[temp]=-1;
				size++;
				
			}
			b[total]=size;
			size=0;
			total++;
		}
		
		
		//total=0
	}
}


long int find_lcm(long int*b,long int total)
{
	
}
