#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 10000


typedef struct load_
{
	int start;
	int value;
	int end;
}load;


load input[100010];

load stack[100010];
int top = 0;

char line[10000];


int main()
{	
	void merge(load *a,int i,int j);

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

	merge(input,0,n-1);

	/*for(int i=0;i<n ;++i)
	{
		printf("%d %d %d\n",input[i].start,input[i].value,input[i].end );
	}*/




	for(int i=0;i<n;++i)
	{
		if(top == 0)
		{
			stack[top] = input[i];
			top++;
		}

		else
		{
			while((top > 0)&&(stack[top-1].start >= input[i].start)&&(input[i].value > stack[top-1].value))	//Check if starting times are equal
			{
				top--;
			}
			if(top == 0)
			{
				stack[top] = input[i];
				top++;
			}
			else
			{	
				if(stack[top-1].end < input[i].start)
				{
					stack[top].start = stack[top-1].end;
					stack[top].value = 0;
					stack[top].end = input[i].start;
					top++;

					stack[top].start = input[i].start;
					stack[top].value = input[i].value;
					stack[top].end = input[i].end;
					top++;
				}
				else if(stack[top-1].end == input[i].start)
				{
					stack[top].start = input[i].start;
					stack[top].value = input[i].value;
					stack[top].end = input[i].end;
					top++;	
				}
				else
				{	

					if(stack[top-1].value > input[i].value)	//check if value is equal
					{	
						if(stack[top-1].end < input[i].end)
						{	
							stack[top].start = stack[top-1].end;
							stack[top].value = input[i].value;
							stack[top].end = input[i].end;
							top++;
						}
						/*stack[top-1].end = input[i].start;
						stack[top].start = input[i].start;
						stack[top].value = input[i].value;
						stack[top].end = input[i].end;
						top++;*/	
					}
					else if(stack[top-1].value == input[i].value)
					{
						if(stack[top-1].end < input[i].end)
						{
							stack[top-1].end = input[i].end;
						}
					}
					else
					{	
						if(stack[top-1].end <= input[i].end)
						{
							stack[top-1].end = input[i].start;
							stack[top].start = input[i].start;
							stack[top].value = input[i].value;
							stack[top].end = input[i].end;
							top++;	
						}
						else
						{	
							int temp;
							temp = stack[top-1].end;
							stack[top-1].end = input[i].start;
							stack[top].start = input[i].start;
							stack[top].value = input[i].value;
							stack[top].end = input[i].end;
							top++;
							stack[top].start = input[i].end;
							stack[top].value = stack[top-2].value;
							stack[top].end = temp;
							top++;

						}
						
					}
					
				}
			 
			}
		}
	}


	//printf("Top is : %d\n",top);

	for(int i=0;i<top;++i)
	{
		printf("%d %d\n",stack[i].start,stack[i].value);
	}

	printf("%d %d\n",stack[top-1].end,0);

} 




void merge(load *a,int i,int j)
{
	int mid;
	load *b;	//Temporary array
	int p=0,q=0,count=0;	//Loop variables
	mid=(i+j)/2;
	
	b = (load*) malloc(sizeof(load)*(j-i+1));
	
	if(i==j)
	{
		return;
	}
	else
	{	
		p=i;
		q=mid+1;
		count=0;
		
		merge(a,i,mid);
		merge(a,mid+1,j);
		
		while((p<=mid)&&(q<=j))
		{
			if(a[p].start<a[q].start)
			{
				b[count]=a[p];
				p++;
				count++;
			}
			else
			{
				b[count]=a[q];
				q++;
				count++;
			}
			
		}
		
		
		if(p<=mid)
		{
			while(p<=mid)
			{
				b[count]=a[p];
				p++;
				count++;
			}
		}
		
		else if(q<=j)
		{
			while(q<=j)
			{
				b[count]=a[q];
				q++;
				count++;
			}
		}
		
		for(p=0;p<(j-i+1);++p)
		{
			a[i+p]=b[p];
		}
		
		free(b);
		
		return;
		
	}
	
}