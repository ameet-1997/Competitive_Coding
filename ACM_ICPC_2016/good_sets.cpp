#include <stdio.h>
#include <algorithm>

using namespace std;

#define mod 1000000007


int a[1000000];
int input[1000000];
int answer[1000000];


int main()
{
	int test;
	scanf("%d",&test);

	for(int tester=0;tester<test;++tester)
	{
		for(int i=0;i<1000000;++i)
		{
			a[i] = 0;
		}

		int n;

		scanf("%d",&n);

		for(int j=0;j<n;++j)
		{
			scanf("%d",&input[j]);
		}

		sort(input,input+n);

		for(int i=0;i<n;++i)
		{
			a[input[i]] = 1;	//Setting it equal to 1 if it exists
			answer[i] = 1;
		}

		for(int i=0;i<n;++i)
		{
			int temp = input[i];
			int check = 2;

			temp = check*input[i];

			while(temp <= input[n-1])
			{
				if(a[temp] == 1)
				{
					answer[temp] = answer[temp] + answer[input[i]];
					answer[temp] = answer[temp]; 
				}
				check++;

				temp = check*input[i];
			}

		}

		int sum = 0;

		for(int i=0;i<n;++i)
		{
			sum = sum + answer[i];
		}

		printf("%d\n",sum);



	}
}
