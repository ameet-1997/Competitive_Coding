#include<stdio.h>

int main()
{	int choice(char*);
	int test,divisor,inputs,total=0;
	char data[50];
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&inputs);
		scanf("%s",data);
		if(data[0]=='I')
		{
			divisor=200;
		}
		else
		{
			divisor=400;
		}
		for(int j=0;j<inputs;++j)
		{
			scanf("%s",data);
			total=total+choice(data);
			
		}
		total=total/divisor;
		printf("%d\n",total);
		total=0;
	}
}


int choice(char* data)
{	int points;
	if(data[8]=='W')
	{
		scanf("%d",&points);
		if(points<20)
		{
			return 300+20-points;
		}
		else
		{
			return 300;
		}
	}
	else if(data[8]=='R')
	{
		return 300;
	}
	else if(data[8]=='D')
	{
		scanf("%d",&points);
		return points;
	}
	else if(data[8]=='H')
	{
		return 50;
	}
	
}
