#include<stdio.h>

int *matrix,*check;
int test;
int n,m;
int a,b;
float *dist;
	
int main()
{	void path(int,int);	
	scanf("%d",&test);
	
	for(int i=0;i<test;++i)
	{	int x,y,z;
		scanf("%d %d",&n,&m);
		
		matrix=new int[n*n];
		check=new int[n*n];
		
		dist=new float[n];
		
		for(int j=0;j<n;++j)
		{
			dist[j]=0;
		}
		
		for(int p=0;p<n;++p)
		{
			for(int q=0;q<n;++q)
			{
				matrix[p*n+q]=0;
				check[p*n+q]=0;
			}
		}
		
		for(int j=0;j<m;++j)
		{
			scanf("%d %d %d",&x,&y,&z);
			matrix[(x-1)*n+(y-1)]=z;
		}
		
		scanf("%d %d",&a,&b);
		path(a,1);
		if(dist[b-1]<0.5)
		{
			printf("-1\n");
		}
		else
		{
			printf("%.6f",dist[b-1]);
		}
		
		delete[] matrix;
		delete[] check;
		delete[] dist;
	}
}

void path(int a,int len)
{	float temp;
	for(int j=0;j<n;++j)
	{	if(matrix[(a-1)*n+j]==0)
		{
			continue;
		}
		
		if(check[j*n+(a-1)]!=0)
		{
			continue;
		}
		
		temp=(dist[a]*(len-1)+matrix[(a-1)*n+j])/len;
		
		if(temp<dist[j])
		{
			dist[j]=temp;
		}
		path(j+1,len+1);
	}
}
