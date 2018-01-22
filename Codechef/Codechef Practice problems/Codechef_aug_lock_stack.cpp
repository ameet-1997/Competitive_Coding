#include<stdio.h>


int **matrix;
int *mark;
int *ans;
int flag=0;
int n;
long int count=0;
int main()
{	void check(int);
	int test,temp;
	
	scanf("%d",&test);
	for(int z=0;z<test;++z)
	{	flag=0;
		n=0;
		count=0;
		
		scanf("%d",&n);
		
		matrix=new int*[n];
		mark=new int[n];
		for(int i=0;i<n;++i)
		{
			scanf("%d",&temp);
			count=count+temp;
			matrix[i]=new int[temp];
			mark[i]=temp-1;
			for(int j=0;j<temp;++j)
			{
				scanf("%d",&matrix[i][j]);
			}
		}
		
		ans=new int[count];
		
		for(int j=0;j<count;++j)
		{
			scanf("%d",&ans[j]);
		}
		
		//printf("\nCount: %d \n",count);
		
		check(count);
		
		if(flag==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		
		for(int l=0;l<n;++l)
		{
			delete[] matrix[l];
		}
		delete[] matrix;
		delete[] mark;
		delete[] ans;
		
		
	}
}


void check(int index)
{	if(flag==1)
	{
		return;
	}
	if(index==0)
	{
		flag=1;
		return;
	}
	
	else
	{
		for(int i=0;i<n;++i)
		{	if(mark[i]>=0)
			{
				if(matrix[i][mark[i]]==ans[count-index])
				{	
					mark[i]--;
					check(index-1);
					mark[i]++;
				}
			}
			
		}
	}
}
