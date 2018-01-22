#include <stdio.h>


char s[1000000];
int police_position[1000000];	//Initially 1

int main()
{
	int n;	//No of police
	int m;	//Total steps
	int l;	//Initial location of the thief

	int thief_position;
	scanf("%d%d%d",&n,&m,&l);

	int answer1,answer2;

	thief_position = l;

	int flag = 0;	//Not caught

	for(int i=0;i<n;++i)
	{
		police_position[i] = 1;
	}


	for(int i=0;i<m;++i)
	{
		scanf("%s",s);

		for(int j=0;j<n;++j)
		{
			if(police_position[j] == thief_position)
			{
				flag = 1;

				//printf("%d %d\n",i,j+1);	//i is move number and j is police position
				answer1 = i;
				answer2 = j+1;

				for(int z=i;z<m-1;++z)		//Taking the remaining input
				{
					scanf("%s",s);
				}
				break;
			}
		}

		if(flag == 1)
		{
			break;
		}


		if(s[0] == 'U')
		{	
			if(thief_position != 1)
			{
				thief_position = thief_position/2;
			}
			
		}
		else if(s[0] == 'L')
		{
			thief_position = thief_position*2;
		}
		else if(s[0] == 'R')
		{
			thief_position = thief_position*2+1;
		}


		for(int j=0;j<n;++j)
		{
			if(s[j+1] == 'U')
			{
				if(police_position[j] != 1)
				{
					police_position[j] = police_position[j]/2;
				}
			}
			else if(s[j+1] == 'L')
			{
				police_position[j] = police_position[j]*2;
			}
			else if(s[j+1] == 'R')
			{
				police_position[j] = police_position[j]*2+1;
			}

			if(police_position[j] == thief_position)
			{
				flag = 1;

				//printf("%d %d\n",i+1,j+1);	//i is move number and j is police position

				answer1 = i+1;
				answer2 = j+1;

				for(int z=i;z<m-1;++z)		//Taking the remaining input
				{
					scanf("%s",s);
				}
				break;
			}
		}


		if(flag == 1)
		{
			break;
		}

	}


	if(flag == 0)
	{
		printf("0 0\n");
	}
	else
	{
		printf("%d %d\n",answer1,answer2);
	}

} 
