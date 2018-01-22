#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);

	char s[100010];
	char s1[100010];
	int top = 0;
	char c;

	char check1,check2,check3;

	for(int zz = 0;zz<test;++zz)
	{	
		top = 0;
		scanf("%s",s1);

		if((s1[0]=='\0')||(s1[1]=='\0')||(s1[2]=='\0'))		//If string size is less than 3
		{
			printf("No\n");
			continue;
		}

		//check1 = s[0] = s1[0];
		check1 = s1[0];
		check2 = s1[1];

		s[0] = s1[0];
		s[1] = s1[1];
		//s[2] = s1[2];

		top = 2;

		int i=2;
 
		while(s1[i]!='\0')
		{
			if(s1[i] == 'M')
			{
				if((check1 == 'I')&&(check2 == 'E'))
				{
					top = top - 2;

					if(top == 0)
					{
						i++;

						if(s1[i] == '\0')
						{
							break;
						}

						s[0] = s1[i];
						i++;

						if(s1[i] == '\0')
						{
							break;
						}

						s[1] = s1[i];

						check1 = s[0];
						check2 = s[1];
						top = 2;

					}
					else if(top == 1)
					{
						check1 = s[0];
						i++;

						if(s1[i] == '\0')
						{
							break;
						}

						check2 = s1[i];
						top = 2;
					}
					else
					{
						check1 = s[top-2];
						check2 = s[top-1];
					}
				}
				else
				{
					s[top] = s1[i];
					top++;
					check1 = s[top-2];
					check2 = s[top-1];
				}



			}
			else
			{
				s[top] = s1[i];
				top++;
				check1 = s[top-2];
				check2 = s[top-1];
			}

			i++;
		}

		if(top%3!=0)
		{
			printf("No\n");
			continue;
		}

		int flag = 0;

		for(int i=0;i<top;++i)
		{
			if(i%3 == 0)
			{
				if(s[i] != 'I')
				{
					flag = 1;
					break;
				}
			}

			if(i%3 == 1)
			{
				if(s[i] != 'E')
				{
					flag = 1;
					break;
				}
			}

			if(i%3 == 2)
			{
				if(s[i] != 'M')
				{
					flag = 1;
					break;
				}
			}
		}

		if(flag == 1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
} 
