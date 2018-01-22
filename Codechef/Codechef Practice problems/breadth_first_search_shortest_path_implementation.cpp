#include<stdio.h>

int main()
{
	printf("Enter the number of nodes : ");
	int n,graph[20][20],explored[20],start=0,end=0,queue[1000],unexplored,layer=0;
	scanf("%d",&n);
	printf("Please enter the adjacency matrix\n");
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%d",&graph[i][j]);
		}
		
	}
	
	for(int i=0;i<n;++i)
	{
		explored[i]=0;
	}
	
	printf("I was here\n");
	
	unexplored=n-1;
	explored[0]=0;
	layer=1;
	
	queue[0]=0;
	while(unexplored!=0)
	{
		for(int k=1;k<n;++k)
		{
			if((graph[queue[start]][k]>0)&&(explored[k]==0))
			{
				queue[end+1]=k;
				end=end+1;
				explored[k]=explored[queue[start]]+1;
				unexplored--;
			}
		}
		start=start+1;
	}
	
	printf("The distances are as follows\n");
	
	for(int i=0;i<n;++i)
	{
		printf("%d:%d	",i,explored[i]);
	}
	
	
}
