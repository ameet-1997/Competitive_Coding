#include<stdio.h>

int main()
{
	int x1,x2,v1,v2,ans;
	
	scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
	
	ans=(x1-x2)%(v2-v1);
	if((ans==0)&&((x1-x2)*(v2-v1)>0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
