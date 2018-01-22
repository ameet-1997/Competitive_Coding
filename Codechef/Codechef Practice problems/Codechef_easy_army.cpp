#include<stdio.h>

int main()
{	long int test,n,m,chosen,temp;
	long int* max;
	//printf("Enter the number of test cases : ");
	scanf("%d",&test);
	for(long int i=0;i<test;++i)
	{
		//printf("\nEnter the value of N and M in that order : ");
		scanf("%d%d",&n,&m);
		max=new long int[n];
		//printf("Enter the soldier chosen : ");
		scanf("%d",&chosen);
		
		for(long int k=0;k<chosen;++k)
		{
			max[k]=chosen-k;
		}
		for(long int k=chosen;k<n;++k)
		{
			max[k]=k-chosen;
		}
		
		for(long int j=1;j<m;++j)
		{
			//printf("Enter the soldier chosen : ");
			scanf("%d",&chosen);
			for(long int k=0;k<chosen;++k)
			{	temp=chosen-k;
				if(temp>max[k])
				max[k]=temp;
			}
			for(long int k=chosen+1;k<n;++k)
			{
				if((k-chosen)>max[k])
				{
					max[k]=temp;
				}
			}
		}
		for(long int l=0;l<n;++l)
		{
			printf("%d ",max[l]);
		}
		printf("\n");
		delete[] max;
	}
}
