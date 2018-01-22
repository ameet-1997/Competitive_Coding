#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max_size 10000


typedef struct load_
{
	int start;
	int value;
	int end;
}load;


load input[100010];


int *a;

int top = 0;

char line[10000];

int main()
{
	char *buffer = NULL;

	int n;
	scanf("%d\n",&n);


	for(int i=0;i<n;++i)		//Check for error condition
	{	
		fgets(line,max_size,stdin);
		//printf("here\n");
		buffer = strtok(line," \n");
		if(buffer == NULL)
		{
			printf("ERROR\n");
			exit(0);
		}
		input[i].start = atoi(buffer);

		buffer = strtok(NULL," \n");
		
		if(buffer == NULL)
		{
			printf("ERROR\n");
			exit(0);
		}

		input[i].value = atoi(buffer);


		buffer = strtok(NULL," \n");
		
		if(buffer == NULL)
		{
			printf("ERROR\n");
			exit(0);
		}

		input[i].end = atoi(buffer);

		if(input[i].end <= input[i].start)
		{
			printf("ERROR\n");
			exit(0);
		}

		/*if(input[i].start < 0)
		{
			printf("ERROR\n");
			exit(0);	
		}*/

		//scanf("%d%d%d",&input[i].start,&input[i].value,&input[i].end);
	}

	int max = 0,min = INT_MAX;

	for(int i=0;i<n;++i)
	{
		if(input[i].start < min)
		{
			min = input[i].start;
		}

		if(input[i].end > max)
		{
			max = input[i].end;
		}
	}

	//printf("--%d %d--\n",min,max);

	a = (int*) malloc(sizeof(int)*(max-min+1));

	for(int i=0;i<max-min+1;++i)
	{
		a[i] = 0;
	}


	for(int i=0;i<n;++i)
	{
		for(int j=input[i].start;j<input[i].end;++j)
		{
			if(a[j-min] < input[i].value)
			{
				a[j-min] = input[i].value;
			}
		}
	}


	for(int i=0;i<max-min+1;++i)
	{
		int m = i;

		while((i<max-min+1)&&(a[i] == a[m]))
		{
			i++;
		}

		if(i == max-min+1)
		{	
			printf("%d %d\n",m+min,a[m]);
			//printf("%d %d\n",max-min+1,0);
			break;
		}

		printf("%d %d\n",m+min,a[m]);

		i--;

	}

	free(a);


}