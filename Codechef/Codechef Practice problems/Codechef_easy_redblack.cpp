#include<stdio.h>
#include<math.h>

int main()
{
	int query,colour=0,x,y,level1,level2;
	char choice,waste;
	scanf("%d",&query);
	for(int i=0;i<query;++i)
	{
		scanf("%c%c",&choice,&choice);
		if(choice=='i')
		{
			colour=!colour;
		}
		else
		{
			scanf("%c",&waste);
			scanf("%d%d",&x,&y);
			level1=floor(log2(x))+1;
			level2=floor(log2(y))+1;
			if(colour)
			{
				if((level1%2==1)||(level2%2==1))
				{
					printf("%d\n",(level2-level1)/2+1);	
				}
				else
				{
					printf("%d\n",(level2-level1)/2);
				}
			}
			else
		}
	}
}
