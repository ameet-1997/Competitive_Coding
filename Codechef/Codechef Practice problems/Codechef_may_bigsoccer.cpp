#include<stdio.h>

int *ball,*strength;
int n,m;
int main()
{	
	void find_next(int,int);
	void init(void);
	int test;
	long int s;
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{	
		scanf("%d",&n);//Number of dogs
		scanf("%d",&m);//The number of pass strengths
		scanf("%d",&s);//The dog which has the ball initially
		ball=new int[n+1];
		strength=new int[m];
		init();
		for(int j=0;j<m;++j)
		{
			scanf("%d",&strength[j]);
		}
		//printf("\n----This is where the problem starts----\n");
		find_next(s,0);
		for(int j=1;j<=n;++j)
		{
			printf("%d ",ball[j]);
		}
		printf("\n");
		delete[] ball;
		delete[] strength;
		
	}
	return 0;
}

void find_next(int a,int k)
{
	if(k==m)
	{
		ball[a]++;
		return;
	}
	else
	{
		if((a+strength[k])<=n)
		{
			find_next(a+strength[k],k+1);
		}
		if((a-strength[k])>=0)
		{
			find_next(a-strength[k],k+1);
		}
		
	}
	return;
}


void init(void)
{
	for(int i=0;i<=n;++i)
	{
		ball[i]=0;
	}
}
