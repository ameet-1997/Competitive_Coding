#include <stdio.h>
#include <string.h>

int main()
{
	char s[200],t[200];
	int k;

	scanf("%s",s);
	scanf("%s",t);

	scanf("%d",&k);


	int len_s,len_t;

	len_s = strlen(s);
	len_t = strlen(t);

	int matching_till = 0;

	int min = len_s;
	if(len_t < len_s)
	{
		min = len_t;
	}

	int index;

	for(index = 0;index < min ;++index)
	{
		if(s[index] != t[index])
		{
			break;
		}
	}



	int operations = (len_s - index) + (len_t - index);

	if(k < operations)
	{
		printf("No\n");
	}
	else if(k == operations)
	{
		printf("Yes\n");
	}
	else
	{
		if( (k-operations)%2 == 0)
		{
			printf("Yes\n");
		}
		else if(k >= len_s + len_t)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

}