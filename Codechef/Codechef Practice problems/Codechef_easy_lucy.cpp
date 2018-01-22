#include<stdio.h>
#include<string.h>

int main()
{
	int test,n,min,input,status=1;;
	char name[5],minname[5];
	scanf("%d",&test);
	for(int i=0;i<test;++i)
	{
		scanf("%d",&n);
		scanf("%s%d",name,&input);
		min=input;
		strcpy(minname,name);
		for(int j=1;j<n;++j)
		{
			scanf("%s%d",name,&input);
			if(input<min)
			{
				min=input;
				strcpy(minname,name);
				status=1;	
			}
			else if(input==min)
			{
				status=0;
			}
		}
		if(status==0)
		{
			printf("Nobody wins.\n");
		}
		else
		{
			printf("%s\n",minname);
		}
		
	}
}
