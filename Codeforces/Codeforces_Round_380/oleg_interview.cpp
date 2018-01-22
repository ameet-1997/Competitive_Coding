#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;

	char a[200];
	cin>>n;

	cin>>a;	//Take input


	for(int i=0;i<n;++i)
	{
		if(a[i]!='o')
		{
			printf("%c",a[i]);
		}
		else
		{
			int excess = 0;
			i++;

			while((i+1 < n)&&(a[i] == 'g')&&(a[i+1] == 'o'))
			{
				excess++;
				i = i + 2;
			}
			i--;

			if(excess == 0)
			{
				printf("o");
			}
			else
			{
				printf("***");
			}
		}
	}

	printf("\n");
} 
