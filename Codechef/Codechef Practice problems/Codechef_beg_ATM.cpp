#include<stdio.h>

int main()
{
	int x;
	double y;
	scanf("%d",&x);
	scanf("%lf",&y);
	if((x%5!=0)||(y-0.50<x))
	{
		printf("%.2lf",y);
	}
	else
	{
		printf("%.2lf",y-x-0.50);
	}
}
