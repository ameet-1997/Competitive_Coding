#include <stdio.h>

int main()
{
	int n;	//Number of weapons

	int even=0;

	int odd=0;

	int temp;

	scanf("%d",&n);	//Number of soldiers

	for(int i=0;i<n;++i)
	{
		scanf("%d",&temp);

		if(temp%2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}

	if(even>odd)
	{
		printf("READY FOR BATTLE\n");
	}
	else
	{
		printf("NOT READY\n");
	}

} 
