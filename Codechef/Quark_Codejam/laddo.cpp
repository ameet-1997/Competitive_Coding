#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int test;
	cin>>test;

	//int a[200];

	int temp;

	for(int zz=0;zz<test;++zz)
	{
		int n;
		cin>>n;

		int answer = 0;

		for(int j=0;j<n;++j)
		{
			cin>>temp;

			if(temp%2 == 1)
			{
				answer++;
			}
		}

		if(answer%2 == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

	}
} 
